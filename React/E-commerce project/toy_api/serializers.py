from django.contrib.auth.password_validation import validate_password
from rest_framework_simplejwt.serializers import TokenObtainPairSerializer
from rest_framework import serializers
from rest_framework_simplejwt.tokens import Token

from toy_api.models import User, Profile, Category, Product, Cart, CartItem, Order, OrderItem, ProductImage

class MyTokenObtainPairSerializer(TokenObtainPairSerializer):
    @classmethod
    def get_token(cls, user):
        token= super().get_token(user)
        token['full_name']=user.full_name
        token['email']=user.email
        token['username']=user.username
        return token
    
class RegisterSerializer(serializers.ModelSerializer):
    password=serializers.CharField(write_only=True, required=True, validators=[validate_password])
    password2=serializers.CharField(write_only=True, required=True)

    class Meta:
        model=User
        fields=['full_name', 'email', 'password', 'password2']

    def validate(self, data):
        if data['password']!=data['password2']:
            raise serializers.ValidationError({"password":"Password fields didn't match"})
        return data 
    def create(self, validated_data):
        user=User.objects.create(full_name=validated_data['full_name'], email=validated_data['email'])
        email_username, nm=user.email.split("@")
        user.username=email_username

        user.set_password(validated_data['password'])
        user.save()
        return user

class UserSerializer(serializers.ModelSerializer):
    class  Meta:
        model=User
        fields="__all__" 
class ProfileSerializer(serializers.ModelSerializer):
    class  Meta:
        model=Profile
        fields="__all__" 
class CategorySerializer(serializers.ModelSerializer):
    def get_product_count(self, category):
        return category.products.count()
    class Meta:
        model=Category
        fields=['id', 'title', 'slug', 'product_count']
class ProductSerializer(serializers.ModelSerializer):
    class Meta:
        model=Product
        fields="__all__"

class ProductImageSerializer(serializers.ModelSerializer):
    class Meta:
        model=ProductImage
        fields="__all__"

class CartSerializer(serializers.ModelSerializer):
    class Meta:
        model=Cart
        fields=['profile', 'session_id', 'created_at']


class CartItemSerializer(serializers.ModelSerializer):
    class Meta:
        model=CartItem
        fields=['cart', 'product', 'quantity', 'price', 'total_price']
class OrderSerializer(serializers.ModelSerializer):
    class Meta:
        model=Order
        fields="__all__"

class DashboardStatsSerializer(serializers.Serializer):
    total_users = serializers.IntegerField()
    total_products = serializers.IntegerField()
    total_orders = serializers.IntegerField()
    total_categories = serializers.IntegerField()
    total_revenue = serializers.DecimalField(max_digits=12, decimal_places=2, coerce_to_string=False)
    recent_orders = serializers.ListField(child=serializers.DictField())
   