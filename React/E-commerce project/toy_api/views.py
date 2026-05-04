from django.shortcuts import render
from django.http import JsonResponse
from django.core.mail import EmailMultiAlternatives
from django.template.loader import render_to_string
from django.conf import settings
from django.contrib.auth.tokens import default_token_generator
from django.utils.http import urlsafe_base64_decode
from django.utils.encoding import force_bytes
from django.db.models import Sum,Count
#rf
from rest_framework import status
from rest_framework.decorators import api_view, permission_classes
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework_simplejwt.views import TokenObtainPairView
from rest_framework import generics
from rest_framework.permissions import AllowAny, IsAuthenticated
from rest_framework_simplejwt.tokens import RefreshToken

from drf_yasg import openapi
from drf_yasg.utils import swagger_auto_schema
from datetime import datetime

import json
import random
from toy_api.serializers import MyTokenObtainPairSerializer, RegisterSerializer, UserSerializer, ProfileSerializer, CategorySerializer,ProductSerializer,ProductImageSerializer, CartSerializer, OrderSerializer,DashboardStatsSerializer
from toy_api.models import User, Profile, Category, Product, ProductImage, Cart, CartItem, Order, OrderItem

class MyTokenObtainPairView(TokenObtainPairView):
    serializer_class =MyTokenObtainPairSerializer

class RegisterView(generics.CreateAPIView):
    queryset=User.objects.all()
    permission_classes=[AllowAny]
    serializer_class=RegisterSerializer

class ProfileView(generics.CreateAPIView):
    permission_classes =[AllowAny]
    serializer_class=ProfileSerializer

    def get_object(self):
        user_id=self.kwargs['user_id']
        user=User.objects.get(id=user_id)
        profile=Profile.objects.get(user=user)
        return profile
    
class CategoryListApiView(generics.ListAPIView):
    serializer_class=CategorySerializer
    permission_classes=[AllowAny]
    def get_queryset(self):
        return Category.objects.all()
    
class ProductCategoryListAPIView(generics.ListAPIView):
    serializer_class=ProductSerializer
    permission_classes=[AllowAny]
    def get_queryset(self):
        category_slug=self.kwargs['category_slug']
        category=Category.objects.get(slug=category_slug)
        product=Product.objects.filter(category=category,is_available=True)
        return product
    
class ProductListAPIView(generics.ListAPIView):
    serializer_class=ProductSerializer
    permission_classes=[AllowAny]

class CartListApiView(generics.ListAPIView):
    serializer_class=CartSerializer
    permission_classes=[AllowAny ]

class OrderListApiView(generics.ListAPIView):
    serializer_class=OrderSerializer
    permission_classes=[AllowAny]

class DashboardStatsView(APIView):
    permission_classes=[IsAuthenticated]

    def get(self, request, user_id=None):
        user=request.user
        if not user.is_staff:
            return Response({"error":"Unauthorised Login"})
        total_users=User.objects.count()
        total_products=Product.objects.count()
        total_orders=Order.objects.count()
        total_categories=Category.objects.count()
        total_rev=Order.objects.aggregate(total=Sum('total'))['total'] or 0
        total_sold=OrderItem.objects.aggregate(total=Sum('quantity'))['total'] or 0

        recent_orders=Order.objects.order_by('-created_at')[:5].values('id', 'total', 'status', 'created_at')
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