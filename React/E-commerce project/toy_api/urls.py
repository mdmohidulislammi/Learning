from django.urls import path,include
from rest_framework_simplejwt.views import TokenRefreshView
from toy_api.views import MyTokenObtainPairView, RegisterView, ProfileView, CategoryListApiView, ProductCategoryListAPIView, ProductListAPIView,CartListApiView, OrderListApiView,DashboardStatsView
urlpatterns = [
   path('user/token/', MyTokenObtainPairView.as_view()),
   path('user/token/refresh', TokenRefreshView.as_view()),
   path('user/register/', RegisterView.as_view()),
   path('user/profile/<user_id>/', ProfileView.as_view()),

#    product endpoint
   path('products/', ProductListAPIView.as_view()),    
   path('products/category/list/', CategoryListApiView.as_view()),
   path('products/category/product/<category_slug>/', ProductCategoryListAPIView.as_view()),
   path('products/carts/', CartListApiView.as_view()),   
   path('products/orders/', OrderListApiView.as_view()),   

# Dashboard
   path('dashboard/',DashboardStatsView.as_view()),

]
