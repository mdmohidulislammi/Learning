from django.urls import path, include
from rest_framework_simplejwt.views import TokenRefreshView
from toy_api.views import (
    MyTokenObtainPairView,
    RegisterView,
    ProfileView,
    CategoryListApiView,
    ProductCategoryListAPIView,
    ProductListAPIView,
    CartListApiView,
    OrderListApiView,
    DashboardStatsView,
    DashboardProductListView,
    DashboardProductCreateApi,
    DashboardProductUpdateApi,
    DashboardProductDeleteApi,
)

urlpatterns = [
    path("user/token/", MyTokenObtainPairView.as_view()),
    path("user/token/refresh", TokenRefreshView.as_view()),
    path("user/register/", RegisterView.as_view()),
    path("user/profile/<user_id>/", ProfileView.as_view()),
    #    product endpoint
    path("products/", ProductListAPIView.as_view()),
    path("products/category/list/", CategoryListApiView.as_view()),
    path(
        "products/category/product/<category_slug>/",
        ProductCategoryListAPIView.as_view(),
    ),
    path("carts/", CartListApiView.as_view()),
    path("orders/", OrderListApiView.as_view()),
    # Dashboard
    path("dashboard/", DashboardStatsView.as_view()),
    path("dashboard/user/<user_id>/", DashboardProductListView.as_view()),
    path("dashboard/create-product/", DashboardProductCreateApi.as_view()),
    path("dashboard/update-product/", DashboardProductUpdateApi.as_view()),
    path("dashboard/product/<int:id>/delete/", DashboardProductDeleteApi.as_view())
]
