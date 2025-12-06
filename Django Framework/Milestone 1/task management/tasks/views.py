from django.shortcuts import render
from django.http import HttpResponse
from tasks.forms import TaskModelForm
from tasks.models import Employee, Task
def manager(request):
    return render(request, "all_html/manager.html")
def users(request):
    return render(request, "all_html/users.html")

def create_task(request):
    employees=Employee.objects.all()
    form=TaskModelForm() #by default get
    if request.method=="POST":
        form=TaskModelForm(request.POST)
        if form.is_valid():
            form.save()

            #  For Django Form Data
    #         data=form.cleaned_data
    #         title=data.get('title')
    #         description=data.get('description')
    #         due_date=data.get('due_date')
    #         assigned_to=data.get('assigned_to')
    #         task=Task.objects.create(title=title, description=description, due_date=due_date)
            
    #         #assign task to employees
    #         for emp_id in assigned_to:
    #             employee=Employee.objects.get(id=emp_id)
    #             task.assigned_to.add(employee)
            return HttpResponse("Task Added Successfully")
    context={"form":form}
    return render(request, "tasks.html", context)