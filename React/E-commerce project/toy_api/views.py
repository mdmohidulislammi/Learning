from django.shortcuts import render
from django.http import JsonResponse
from django.core.mail import EmailMultiAlternatives
from django.template.loader import render_to_string
from django.conf import settings
from django.contrib.auth.tokens import default_token_generator
from django.utils.http import urlsafe_base64_decode
from django.utils.encoding import force_bytes
from django.db.models import Sum, Count

# rf
from rest_framework import status
from rest_framework.decorators import api_view, permission_classes
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework_simplejwt.views import TokenObtainPairView
from rest_framework import generics
from rest_framework.permissions import AllowAny, IsAuthenticated
from rest_framework_simplejwt.tokens import RefreshToken
from rest_framework.parsers import MultiPartParser, FormParser
from drf_yasg import openapi
from drf_yasg.utils import swagger_auto_schema
from datetime import datetime

import json
import random
from toy_api.serializers import (
    MyTokenObtainPairSerializer,
    RegisterSerializer,
    UserSerializer,
    ProfileSerializer,
    CategorySerializer,
    ProductSerializer,
    ProductImageSerializer,
    CartSerializer,
    OrderSerializer,
    DashboardStatsSerializer,
)
from toy_api.models import (
    User,
    Profile,
    Category,
    Product,
    ProductImage,
    Cart,
    CartItem,
    Order,
    OrderItem,
)


class MyTokenObtainPairView(TokenObtainPairView):
    serializer_class = MyTokenObtainPairSerializer


class RegisterView(generics.CreateAPIView):
    queryset = User.objects.all()
    permission_classes = [AllowAny]
    serializer_class = RegisterSerializer


class ProfileView(generics.CreateAPIView):
    permission_classes = [AllowAny]
    serializer_class = ProfileSerializer

    def get_object(self):
        user_id = self.kwargs["user_id"]
        user = User.objects.get(id=user_id)
        profile = Profile.objects.get(user=user)
        return profile


class CategoryListApiView(generics.ListAPIView):
    serializer_class = CategorySerializer
    permission_classes = [AllowAny]

    def get_queryset(self):
        return Category.objects.all()


class ProductCategoryListAPIView(generics.ListAPIView):
    serializer_class = ProductSerializer
    permission_classes = [AllowAny]

    def get_queryset(self):
        category_slug = self.kwargs["category_slug"]
        category = Category.objects.get(slug=category_slug)
        product = Product.objects.filter(category=category, is_available=True)
        return product


class ProductListAPIView(generics.ListAPIView):
    serializer_class = ProductSerializer
    permission_classes = [AllowAny]


class CartListApiView(generics.ListAPIView):
    serializer_class = CartSerializer
    permission_classes = [IsAuthenticated]


class OrderListApiView(generics.ListAPIView):
    serializer_class = OrderSerializer
    permission_classes = [IsAuthenticated]


class DashboardStatsView(APIView):
    permission_classes = [IsAuthenticated]

    def get(self, request, user_id=None):
        user = request.user
        if not user.is_staff:
            return Response({"error": "Unauthorised Login"})
        total_users = User.objects.count()
        total_products = Product.objects.count()
        total_orders = Order.objects.count()
        total_categories = Category.objects.count()
        total_rev = Order.objects.aggregate(total=Sum("total"))["total"] or 0
        total_sold = OrderItem.objects.aggregate(total=Sum("quantity"))["total"] or 0

        recent_orders = Order.objects.order_by("-created_at")[:5].values(
            "id", "total", "status", "created_at"
        )
        data = {
            "total_users": total_users,
            "total_products": total_products,
            "total_orders": total_orders,
            "total_categories": total_categories,
            "total_revenue": total_rev,
            "recent_orders": recent_orders,
        }

        serializer = DashboardStatsSerializer(data=data)
        serializer.is_valid(raise_exception=True)
        return Response(serializer.data)


class DashboardProductListView(generics.ListAPIView):
    serializer_class = ProductSerializer
    permission_classes = [AllowAny]

    def get_queryset(self):
        user_id = self.kwargs["user_id"]
        user = User.objects.get(id=user_id)
        return Product.objects.filter(user=user).order_by("-id")


class DashboardProductCreateApi(generics.CreateAPIView):
    serializer_class = ProductSerializer
    parser_classes = [MultiPartParser, FormParser]
    permission_classes = [IsAuthenticated]

    def create(self, request, *args, **kwargs):
        if not request.user.is_staff and "user_id" in request.data:
            return Response(
                {"error": "Only staff can assign a different user."},
                status=status.HTTP_403_FORBIDDEN,
            )

        if "user_id" not in request.data:
            request.data._mutable = True
            request.data["user"] = request.user.id
            request.data._mutable = False
        else:
            user_id = request.data.get("user_id")
            if not User.objects.filter(id=user_id).exists():
                return Response(
                    {"user_id": "User does not exist."},
                    status=status.HTTP_400_BAD_REQUEST,
                )
            request.data._mutable = True
            request.data["user"] = user_id
            del request.data["user_id"]
            request.data._mutable = False

        category_id = request.data.get("category")
        if category_id and not Category.objects.filter(id=category_id).exists():
            return Response(
                {"category": "Category does not exist."},
                status=status.HTTP_400_BAD_REQUEST,
            )

        serializer = self.get_serializer(data=request.data)
        serializer.is_valid(raise_exception=True)
        self.perform_create(serializer)

        return Response(
            {"message": "Product created successfully.", "product": serializer.data},
            status=status.HTTP_201_CREATED,
        )

    def perform_create(self, serializer):
        serializer.save()


class DashboardProductUpdateApi(generics.UpdateAPIView):
    serializer_class = ProductSerializer
    parser_classes = [MultiPartParser, FormParser]
    permission_classes = [IsAuthenticated]
    queryset = Product.objects.all()
    lookup_field = "id"

    def update(self, request, *args, **kwargs):
        product = self.get_object()

        if not request.user.is_staff and product.user.id != request.user.id:
            return Response(
                {"error": "You do not have permission to update this product."},
                status=status.HTTP_403_FORBIDDEN,
            )

        if "user_id" in request.data:
            if not request.user.is_staff:
                return Response(
                    {"error": "Only staff can reassign product to another user."},
                    status=status.HTTP_403_FORBIDDEN,
                )
            user_id = request.data.get("user_id")
            if not User.objects.filter(id=user_id).exists():
                return Response(
                    {"user_id": "User does not exist."},
                    status=status.HTTP_400_BAD_REQUEST,
                )
            request.data._mutable = True
            request.data["user"] = user_id
            del request.data["user_id"]
            request.data._mutable = False

        category_id = request.data.get("category")
        if category_id and not Category.objects.filter(id=category_id).exists():
            return Response(
                {"category": "Category does not exist."},
                status=status.HTTP_400_BAD_REQUEST,
            )

        partial = kwargs.pop("partial", False)
        serializer = self.get_serializer(product, data=request.data, partial=partial)
        serializer.is_valid(raise_exception=True)
        self.perform_update(serializer)

        if "images" in request.data:
            images_data = (
                request.data.getlist("images")
                if hasattr(request.data, "getlist")
                else request.data.get("images", [])
            )
            if images_data:
                ProductImage.objects.filter(product=product).delete()
                for image_data in images_data:
                    ProductImage.objects.create(product=product, img=image_data)

        return Response(
            {"message": "Product updated successfully.", "product": serializer.data},
            status=status.HTTP_200_OK,
        )

    def perform_update(self, serializer):
        serializer.save()


class DashboardProductDeleteApi(generics.DestroyAPIView):
    permission_classes = [IsAuthenticated]
    queryset = Product.objects.all()
    lookup_field = "id"

    def destroy(self, request, *args, **kwargs):
        product = self.get_object()

        # Check permission: staff or owner
        if not request.user.is_staff and product.user.id != request.user.id:
            return Response(
                {"error": "You do not have permission to delete this product."},
                status=status.HTTP_403_FORBIDDEN,
            )

        product.images.all().delete()

        self.perform_destroy(product)

        return Response(
            {"message": "Product deleted successfully."}, status=status.HTTP_200_OK
        )
