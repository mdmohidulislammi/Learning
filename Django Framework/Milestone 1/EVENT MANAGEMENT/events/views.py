from django.shortcuts import render, redirect
from django.http import HttpResponse
from datetime import date, time
from django.db.models import Q,Count
from django.contrib import messages
from events.models import Event, Category, Participant
from events.forms import Event_form, Category_Details, Participant_form


def organizer_dashboard(request):
    return render(request, 'body.html')

def create_event(request):
    if request.method=='POST':
        category_form=Category_Details(request.POST)
        event_form=Event_form(request.POST)
        participant_form=Participant_form(request.POST)
        if category_form.is_valid() and event_form.is_valid() and participant_form.is_valid():

            category=category_form.save()

            event=event_form.save(commit=False)

            event.category=category

            event.save()
            participant=participant_form.save()
            participant.event.add(event)

            messages.success(request, 'EVENT CREATED SUCCESSFULLY')
            return redirect('create-event')
    else:
        category_form=Category_Details()
        event_form=Event_form()
        participant_form=Participant_form()

    context={'event_form':event_form, 'category_form':category_form, 'participant_form':participant_form}
    return render(request, 'forms.html', context)


def update_event(request, id):
    pass
def delete_event(request, id):
    pass
