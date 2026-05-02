from django.db import models
from django.contrib.auth.models import AbstractUser
from django.db.models.signals import post_save, pre_save, post_delete, pre_delete
from django.utils.text import slugify
from shortuuid.django_fields import ShortUUIDField
import shortuuid
from phonenumber_field.modelfields import PhoneNumberField

class User(AbstractUser):
    username = models.CharField(unique=True, max_length=150)
    email = models.EmailField(unique=True)
    full_name = models.CharField(max_length=100, null=True, blank=True)

    USERNAME_FIELD = 'email'
    REQUIRED_FIELDS = ['username']

    def save(self, *args, **kwargs):
        if self.email:
            email_username = self.email.split("@")[0]
        else:
            email_username = "user"

        if not self.full_name:
            self.full_name = email_username

        if not self.username:
            self.username = email_username

        super().save(*args, **kwargs)

    def __str__(self):
        return self.username


class Profile(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE)
    image = models.FileField(upload_to="image", default="default/default-user.jpg", null=True, blank=True)
    full_name = models.CharField(max_length=150, null=True, blank=True)
    location = models.CharField(max_length=250, null=True, blank=True)
    country = models.CharField(max_length=60, null=True, blank=True)
    cell = PhoneNumberField(region='BD')

    def __str__(self):
        return self.user.username

    def save(self, *args, **kwargs):
        if not self.full_name:
            self.full_name = self.user.full_name
        super().save(*args, **kwargs)


def create_user_profile(sender, instance, created, **kwargs):
    if created:
        Profile.objects.create(user=instance)


def save_user_profile(sender, instance, **kwargs):
    if hasattr(instance, 'profile'):
        instance.profile.save()


post_save.connect(create_user_profile, sender=User)
post_save.connect(save_user_profile, sender=User)