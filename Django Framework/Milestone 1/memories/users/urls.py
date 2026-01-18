from django.contrib import admin
from django.urls import path, include
from users.views import test

urlpatterns = [
    path('dashboard/',test, name='test')
]
