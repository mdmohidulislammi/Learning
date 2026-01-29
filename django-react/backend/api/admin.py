from django.contrib import admin

from api.models import User, Profile, Category, Post, Comment, Bookmarks

admin.site.register(User)
admin.site.register(Profile)
admin.site.register(Post)
admin.site.register(Category)
admin.site.register(Comment)
admin.site.register(Bookmarks)