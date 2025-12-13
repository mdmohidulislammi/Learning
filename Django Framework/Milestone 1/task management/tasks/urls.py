from django.urls import path 
from tasks.views import manager,users, create_task, view_task, update_task, delete_task
urlpatterns = [
  path('manager/', manager, name="manager-dashboard")  , 
  path('dashboard/', users),
  path('create-tasks/', create_task, name="create-task"),
  path("view/", view_task),
  path("update-task/<int:id>", update_task, name='update-task'),
  path("delete-task/<int:id>", delete_task, name='delete-task'),
]