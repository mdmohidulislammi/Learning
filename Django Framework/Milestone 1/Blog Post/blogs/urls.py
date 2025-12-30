from django.urls import path
from blogs.views import posts_by_category,post_detail,login_page
urlpatterns = [
   path('category/<int:category_id>/',posts_by_category,name='posts_by_category'),
   path('post/<int:id>/',post_detail, name='post_detail'),
   path('login/', login_page, name='login_page')
   
]
