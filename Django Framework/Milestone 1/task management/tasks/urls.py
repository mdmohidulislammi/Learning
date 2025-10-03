from django.urls import path 
from tasks.views import home

urlpatterns = [
    path('show-task/', home),
]
