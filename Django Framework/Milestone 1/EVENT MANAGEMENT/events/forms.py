from django import forms 
from events.models import Event, Category, Participant

class Participant_form(forms.ModelForm):
    class Meta:
        model=Participant
        fields=['name', 'email']

class Event_form(forms.ModelForm):
   
    class Meta:
        model=Event 
        fields=['event_name', 'description',  'date', 'time', 'location']
        widgets={
            'date':forms.SelectDateWidget(),
            'time':forms.TimeInput(format='%H:%M'),
            'location':forms.TextInput(),
        }

class Category_Details(forms.ModelForm):
    class Meta:
        model=Category
        fields=['Category_name', 'description']