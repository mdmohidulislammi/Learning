from django import forms
from tasks.models import Task
# Django Basic form
# class TaskForm(forms.Form):
#     title=forms.CharField(max_length=100)
#     description=forms.CharField(widget=forms.Textarea, label="Task Description")
#     due_date=forms.DateField(widget=forms.SelectDateWidget, label="DUE DATE")
#     assigned_to=forms.MultipleChoiceField(widget=forms.CheckboxSelectMultiple, choices=[], label="Assigned To")

#     def __init__(self, *args, **kwargs):
#         # print(args, kwargs)
#         employees=kwargs.pop("employees", [])
#         super().__init__(*args, **kwargs)
#         self.fields['assigned_to'].choices=[(emp.id, emp.name) for emp in employees]

# Django Model form
# class StyleFormMixin:
    #mixing to apply style to form field

class TaskModelForm(forms.ModelForm):
    class Meta:
        model=Task
        fields=['title', 'description', 'due_date', 'assigned_to', 'is_completed', 'project']
        #exclude=['project', 'due_date', 'updated_at']
        widgets={
            'due_date': forms.SelectDateWidget,
            'assigned_to':forms.CheckboxSelectMultiple,
            'title':forms.TextInput(attrs={
            }) 
        }


