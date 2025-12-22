from django.urls import path
from events.views import create_event, organizer_dashboard

urlpatterns = [
    path("form/", create_event,name='create-event'),
    path("organizer-dashboard/",organizer_dashboard, name='organizer_dashboard' )
]
