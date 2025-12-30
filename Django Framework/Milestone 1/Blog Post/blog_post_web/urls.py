
from django.contrib import admin
from django.urls import path, include
from blog_post_web.views import home,posts
from django.conf.urls.static import static
from django.conf import settings
from debug_toolbar.toolbar import debug_toolbar_urls

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', home,name='home'),
    path('posts/',posts,name='posts'),
    path('home/',include("blogs.urls"))

]+static(settings.MEDIA_URL,document_root=settings.MEDIA_ROOT)+debug_toolbar_urls()