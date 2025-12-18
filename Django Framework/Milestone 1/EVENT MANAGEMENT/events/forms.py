from django import forms 
from events.models import Event, Category, Participant

class Event_form(forms.ModelForm):
    participant=forms.ModelMultipleChoiceField(queryset=Participant.objects.all(), widget=forms.CheckboxSelectMultiple, required=False)
    class Meta:
        model=Event 
        fields=['name', 'description', 'participant', 'date', 'time', 'location', 'category' ]
        widgets={
            'date':forms.SelectDateWidget,
            'time':forms.TimeInput(format='%H:%M'),
            'participant':forms.CheckboxSelectMultiple,
            # 'name':forms.TextInput(attr{})
        }
    def __init__(self, *arg, **kwargs):
        super().__init__(*arg, **kwargs)


class Category_Details(forms.ModelForm):
    class Meta:
        model=Category
        fields=['name', 'description']

        

# class Participant_Detail(forms.ModelForm):
#     event=forms.ModelMultipleChoiceField(queryset=Event.objects.all(), 
#                                          widget=forms.CheckboxSelectMultiple,
#                                          required=False,
#                                          label="Please Select Events...")
#     class Meta:
#         model=Participant
#         fields=['name', 'email', 'event']

#     def __init__(self, *args, **kwargs):
#         super().__init__(*args, **kwargs)
#         self.fields['event'].label_from_instance = lambda obj: (
#             f"{obj.name} | {obj.date} | {obj.time} | {obj.location} | Category: {obj.category.name}"
#         )