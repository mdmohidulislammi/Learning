from django.contrib import admin
from toy_api.models import User, Profile, Product, Cart, CartItem, Category


admin.site.register(User)
admin.site.register(Profile)
admin.site.register(Category)
admin.site.register(Product)
admin.site.register(Cart)
admin.site.register(CartItem)