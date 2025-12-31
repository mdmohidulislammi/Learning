from django import forms
from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth.models import User


class Registration_Form(UserCreationForm):
    full_name = forms.CharField(
        max_length=100,
        required=True,
        widget=forms.TextInput(attrs={
            "placeholder": "Full name"
        })
    )

    email = forms.EmailField(
        required=True,
        widget=forms.EmailInput(attrs={
            "placeholder": "Email address"
        })
    )

    class Meta:
        model = User
        fields = ("full_name", "username", "email", "password1", "password2")
        widgets = {
            "username": forms.TextInput(attrs={
                "placeholder": "Choose a unique username"
            }),
            "password1": forms.PasswordInput(attrs={
                "placeholder": "🔒 Enter password"
            }),
            "password2": forms.PasswordInput(attrs={
                "placeholder": "🔒 Confirm password"
            }),
        }
