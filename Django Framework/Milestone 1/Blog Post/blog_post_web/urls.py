
from django.contrib import admin
from django.urls import path, include
from blog_post_web.views import home

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', home,name='home')
]
