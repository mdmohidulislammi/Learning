from django.shortcuts import render,get_object_or_404
from datetime import date 
from blogs.models import Blogs, Category


def posts_by_category(request,category_id):
    current_year=date.today().year
    categories=Category.objects.all()
    blogs=Blogs.objects.filter(status=1,category=category_id).select_related('author', 'category')
    context={
        'year':current_year,
        'categories':categories,
        'blogs':blogs
    }
    return render(request, 'category.html',context)


def post_detail(request,id):
    current_year = date.today().year
    categories = Category.objects.all()
    
    blog = get_object_or_404(Blogs.objects.select_related('author', 'category'),id=id, status=1)
    
    context = {
        'year': current_year,
        'categories': categories,
        'post': blog,  # pass as 'post' to match template variable
    }
    return render(request, 'single_post.html',context)

def login_page(request):
    current_year = date.today().year
    categories = Category.objects.all()
    context={
        'year':current_year,
        'categories':categories
    }
    return render(request, 'login.html', context)