from django.shortcuts import render, redirect, get_object_or_404
from django.template.defaultfilters import slugify
from datetime import date
from django.contrib import messages
from django.db.models import Q
from django.contrib.auth import authenticate, logout, login
from django.contrib.auth.models import User
from django.contrib.auth.decorators import login_required
from memories.forms import LoginForm, RegisterForm, MemoryForm
from memories.models import Memory

def home(request):
    current_year=date.today().year
    context={
        "year":current_year,
    }
    return render(request, 'home.html', context)


def create_memory(request):
    current_year=date.today().year
    if request.method == "POST":
        form = MemoryForm(request.POST, request.FILES)
        if form.is_valid():
            post = form.save(commit=False)
            post.author = request.user
            post.save()
            title=form.cleaned_data['title']
            post.slug=slugify(title)
            post.save()
            return redirect("read_memory")
        else:
            id=request.user.id
            messages.error(request, "Post is not valid. Please try again...")
            return redirect('home')
    else:
        form = MemoryForm()

    context={
        'year':current_year,
        'form':form,
    }

    return render(request, 'memory_form.html', context)
def read_memory(request):
    current_year=date.today().year
    memories=Memory.objects.select_related('author',).filter(author_id=request.user.id)
    context={
        'year':current_year,
        'memories':memories
    }
    return render(request,'memories_page.html',context)

def update_memory(request):
    pass
def delete_memory(request):
    pass
def login(request):
    current_year = date.today().year
    form=LoginForm()
    if request.method=='POST':
        form=LoginForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('home')
        else:
            messages.error(request,"Form is not valid")
            return redirect('home')
    
    context={
        'year':current_year,
        'form':form
    }
    return render(request, 'login.html', context)
def logOut(request):
    logout(request)
    return redirect('home')
def register(request):
    pass
def delete_user(request):
    pass
