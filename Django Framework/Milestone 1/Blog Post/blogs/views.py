from django.shortcuts import render,get_object_or_404
from datetime import date 
from blogs.models import Blogs, Category
from django.db.models import Q
from django.contrib import messages


# show posts by category
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

# View single post
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




# Search functionality
def searchBlogs(request):
    current_year = date.today().year
    categories = Category.objects.all()
    keyword = request.GET.get('keyword')

    blogs = Blogs.objects.none()

    if keyword:
        blogs = Blogs.objects.select_related('author', 'category').filter(
            Q(title__icontains=keyword) |
            Q(author__username__icontains=keyword) |
            Q(category__category_name__icontains=keyword) |
            Q(blog_body__icontains=keyword),
            status=1
        )
        if not blogs.exists():
            messages.warning(request, 'No data found ...')
    else:
        messages.error(request, 'Your keyword may be wrong , try again...')

    context = {
        'year': current_year,
        'categories': categories,
        'blogs': blogs,
    }
    return render(request, 'posts.html', context)

