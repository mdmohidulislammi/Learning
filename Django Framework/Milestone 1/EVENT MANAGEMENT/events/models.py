from django.db import models

class Event(models.Model):
    name=models.CharField(max_length=200)
    description=models.TextField()
    date=models.DateField()
    time=models.TimeField()
    location=models.TextField()
    category=models.ForeignKey("Category", on_delete=models.CASCADE,default=1)
    

    def __str__(self) -> str:
        return self.name
    
class Category(models.Model):
    name=models.CharField(max_length=100)
    description=models.TextField(blank=True,null=True)
    def __str__(self) -> str:
        return self.name

class Participant(models.Model):
    name=models.CharField(max_length=100)
    email=models.EmailField()
    event=models.ManyToManyField(Event, related_name='participant')
    def __str__(self) -> str:
        return self.name
