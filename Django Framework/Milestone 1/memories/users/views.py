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

# Create your views here.
def dashboard(request):
    current_year=date.today().year
    context={
        'year':current_year
    }
    return render(request, 'dashboard.html', context)
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
def update(request):
    pass
def delete_user(request):
    pass
