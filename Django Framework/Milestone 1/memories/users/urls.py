from django.contrib import admin
from django.urls import path, include
from users.views import login, logOut, dashboard, manager_dashboard

urlpatterns = [
    path('dashboard/', dashboard),
    path('manager/', manager_dashboard),
     path('login/',login, name='signIn' ),
    path('logout/', logOut, name='logOut'), 

]
