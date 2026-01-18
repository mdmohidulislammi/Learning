from django.contrib import admin
from django.urls import path, include
from users.views import login, logOut, dashboard

urlpatterns = [
    path('dashboard/', dashboard),
     path('login/',login, name='signIn' ),
    path('logout/', logOut, name='logOut')
]
