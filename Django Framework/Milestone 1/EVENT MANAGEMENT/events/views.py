from django.shortcuts import render, redirect
from django.http import HttpResponse
from datetime import date, time
from django.db.models import Q,Count
from django.contrib import messages
from events.models import Event, Category, Participant
from events.forms import Event_form, Category_Details


def organizer(request):
    pass

def create_event(request):
    event_form=Event_form(request.POST)
    category_form=Category_Details(request.POST)
    if event_form.is_valid() and category_form.is_valid():
        event=event_form.save()
        category=category_form.save(commit=False)
        event.category_form=category_form
        event.save()
        messages.success(request, "EVENT CREATED SUCCESSFULLY")
        return redirect('create-event')
    context={"event_form":event_form, "catergory_form":category_form}
    return render(request,"events.html", context)


def update_event(request, id):
    pass
def delete_event(request, id):
    pass
