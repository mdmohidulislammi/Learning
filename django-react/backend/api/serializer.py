from django.contrib.auth.password_validation import validate_password
from rest_framework_simplejwt.serializers import TokenObtainPairSerializer
from rest_framework import serializers

from api import models as api_models

class MyTokenObtainPairSerializer(TokenObtainPairSerializer):
    @classmethod
    def getToken(cls, user):
        token=super().get_token(user)
        token['full_name']=user.full_name
        token['username']=user.username
        token['email']=user.email
        return token
    
class RegisterSerializer(serializers.ModelSerializer):
    password=serializers.CharField(write_only=True, required=True, validators=[validate_password])
    password2=serializers.CharField(write_only=True, required=True)
    class Meta:
        models=api_models.User
        fields=['full_name','email', 'password', 'password2']
    def validation(self, attr):
        if attr['password'] != attr['password2']:
            raise serializers.ValidationError({"Password didn't match."})
        return attr
        
    def creation(self, validated_data):
        user=api_models.User.objects.create(
            full_name=validated_data['full_name'],
            email=validated_data['email']
        )
        email_username, null=user.email.split("@")
        user.username=email_username
        user.set_password(validate_password['password'])
        user.save()
        return user
    