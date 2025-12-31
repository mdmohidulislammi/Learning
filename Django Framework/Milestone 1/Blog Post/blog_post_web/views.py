from django.shortcuts import render
from django.http import HttpResponse
from blogs.models import Category,Blogs
from datetime import date

# def base(request):
    # current_year=date.today().year
    # categories=Category.objects.all()
    # context={
    #     'year':current_year,
    #     'categories':categories,
    # }
    # return render(request,'base.html',context)


def home(request):
    current_year=date.today().year
    categories=Category.objects.all()
    featured_posts=Blogs.objects.filter(is_featured=True,status=1)
    normal_post=Blogs.objects.filter(is_featured=False,status=1)
    
    context={
        'featured':featured_posts,
        'posts':normal_post,
        'year':current_year,
        'categories':categories
    }
    return render(request,'home_page.html',context)

def posts(request):
    current_year=date.today().year
    categories=Category.objects.all()
    blogs=Blogs.objects.filter(status=1).select_related('author', 'category')
    context={
        'year':current_year,
        'categories':categories,
        'blogs':blogs
    }
    return render(request,'posts.html',context)

# login funtion
def login_page(request):
    current_year = date.today().year
    categories = Category.objects.all()
    context={
        'year':current_year,
        'categories':categories
    }
    return render(request, 'login.html', context)
# Register funcitonality
def signUp_page(request):
    current_year = date.today().year
    categories = Category.objects.all()
    context={
        'year':current_year,
        'categories':categories
    }
    return render(request, 'register.html', context)