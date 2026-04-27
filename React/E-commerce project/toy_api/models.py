from django.db import models
from django.contrib.auth.models import AbstractUser
from django.db.models.signals import post_save
from django.utils.text import slugify
from shortuuid.django_fields import ShortUUIDField
import shortuuid

class User(AbstractUser):
    username=models.CharField(unique=True, max_length=150)
    email=models.EmailField(unique=True)
    full_name=models.CharField(max_length=100, null =True, blank=True)

    USERNAME_FIELD='email'
    REQUIRED_FIELDS=['username']

    def save(self, *args, **kwargs):
        email_username, name=self.email.split("@")
        if self.full_name =="" or self.full_name == None:
            self.full_name=email_username
        if self.username =="" or self.username==None:
            self.username= email_username
        super(User,self).save(*args, **kwargs)

    def __str__(self) -> str:
        return self.username

class Profile(models.Model):
    user=models.OneToOneField(User, on_delete=models.CASCADE)
    image=models.FileField(upload_to="image", default="default/default-user.jpg", null=True, blank=True)
    full_name=models.CharField(max_length=150, null=True , blank=True)
    location=models.CharField(max_length=250, null=False, blank=False)
    country=models.CharField(max_length=60, null=True, blank=True)
    def __str__(self) -> str:
        return self.user.username
    def save(self, *args, **kwargs):
        
        if self.full_name =="" or self.full_name == None:
            self.full_name=self.user.full_name
        if self.username =="" or self.username==None:
            self.username= self.user.full_name
        super(Profile,self).save(*args, **kwargs)
    
