from django.urls import path
from events.views import create_event


urlpatterns = [
    path("form/", create_event)
]
