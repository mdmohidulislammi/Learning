from django.urls import path
from memories.views import home, create_memory, update_memory, delete_memory, read_memory
urlpatterns = [
    path('',home, name='home'),
    path('create-memory/', create_memory, name='create-memory'),
    path('read-memory/', read_memory, name='read-memory'), 
]
