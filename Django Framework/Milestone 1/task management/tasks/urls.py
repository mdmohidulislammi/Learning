from django.urls import path 
from tasks.views import manager,users, create_task

urlpatterns = [
  path('manager/', manager)  , 
  path('dashboard/', users),
  path('create-tasks/', create_task)
]