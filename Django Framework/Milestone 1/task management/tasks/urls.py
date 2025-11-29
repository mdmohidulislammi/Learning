from django.urls import path 
from tasks.views import manager,users

urlpatterns = [
  path('manager/', manager)  , 
  path('users/', users),
]