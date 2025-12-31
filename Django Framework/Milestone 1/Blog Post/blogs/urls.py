from django.urls import path
from blogs.views import posts_by_category,post_detail,searchBlogs
urlpatterns = [
   path('category/<int:category_id>/',posts_by_category,name='posts_by_category'),
   path('post/<int:id>/',post_detail, name='post_detail'),
   path('search/',searchBlogs, name="searchBlogs")
]
