from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth.models import User
from django import forms

class BWFormMixin(forms.Form):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        for field in self.fields.values():
            field.widget.attrs.update({
                "class": (
                    "w-full px-4 py-2 "
                    "bg-black text-white "
                    "border border-gray-600 rounded-md "
                    "placeholder-gray-400 "
                    "focus:outline-none focus:ring-2 focus:ring-white "
                    "transition"
                    "placeholder:"
                )
            })
            if "placeholder" not in field.widget.attrs:
                field.widget.attrs["placeholder"] = field.label or name.replace("_", " ").title()

class Registration_Form(BWFormMixin,UserCreationForm):
    full_name=forms.CharField(max_length=100, label="Full Name")
    class Meta:
        model=User 
        fields=('full_name', 'username', 'email', 'password1', 'password2')