from django.shortcuts import render
from django.http import HttpResponse

def manager(request):
    return render(request, "all_html/manager.html")
def users(request):
    return render(request, "all_html/users.html")
