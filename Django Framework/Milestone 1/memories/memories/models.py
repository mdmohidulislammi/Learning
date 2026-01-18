from django.db import models
from django.contrib.auth.models import User
# Create your models here.

class Memory(models.Model):
    title=models.CharField(max_length=100)
    slug=models.SlugField(unique=True, blank=True)
    author=models.ForeignKey(User, on_delete=models.CASCADE)
    body=models.TextField(max_length=1000000)
    created_at=models.DateTimeField(auto_now_add=True)
    updated_at=models.DateTimeField(auto_now=True)
    class Meta:
        verbose_name_plural='Memory'
    
    def __str__(self) -> str:
        return self.title
