from django.contrib.auth.password_validation import validate_password
from rest_framework_simplejwt.serializers import TokenObtainPairSerializer
from rest_framework import serializers
from rest_framework_simplejwt.tokens import Token

from toy_api.models import User, Profile, Category, Product, Cart, CartItem, Order, OrderItem

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
        models=User
        fields=['full_name', 'email', 'password', 'password2']

    def validate(self, data):
        if data['password']!=data['password2']:
            raise serializers.ValidationError({"password":"Password fields didn't match"})
        return data 
    def create(self, validated_data):
        user=User.objects.create(full_name=validated_data['full_name'], email=validated_data['email'])
        email_username, nm=user.email.split("@")
        user.username=email_username

        user.set_password(validate_password['password'])
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
        fields=['id', 'name', 'slug', 'product_count']


      
