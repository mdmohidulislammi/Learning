from django.shortcuts import render,redirect
from django.http import HttpResponse
from tasks.forms import TaskModelForm, TaskDetailForm
from tasks.models import Employee, Task
from datetime import date
from django.db.models import Q, Count, Max, Avg
from django.contrib import messages
def manager(request):
        #getting task count
    # total_task=tasks.count()
    # completed_task=Task.objects.filter(status='COMPLETED').count()
    # in_progress=Task.objects.filter(status='IN_PROGRESS').count()
    # pending_task=Task.objects.filter(status='PENDING').count()
    counts=Task.objects.aggregate(total=Count('id'), completed=Count('id', filter=Q(status='COMPLETED')), in_progress=Count('id', filter=Q(status='IN_PROGRESS')), pending=Count('id', filter=Q(status='PENDING')))
    type=request.GET.get('type', 'all')
    base_query=Task.objects.select_related('details').prefetch_related('assigned_to')
    tasks=base_query.all()
    if type=='completed':
        tasks=base_query.filter(status='COMPLETED')
    elif type=='pending':
        tasks=base_query.filter(status='PENDING')
    elif type=='in-progress':
        tasks=base_query.filter(status='IN_PROGRESS')
    elif type=='all':
        tasks=base_query.all()
    context={ 
       "tasks":tasks,
        "counts":counts
    }
    return render(request, "all_html/manager.html", context)
def users(request):
    return render(request, "all_html/users.html")

def create_task(request):

    # employees=Employee.objects.all()
    task_form=TaskModelForm()
    task_detail_form=TaskDetailForm()
   
    if request.method=="POST":
        task_form=TaskModelForm(request.POST)
        task_detail_form=TaskDetailForm(request.POST)   
        if task_form.is_valid() and task_detail_form.is_valid():
            task=task_form.save()
            task_detail=task_detail_form.save(commit=False)
            task_detail.task=task
            task_detail.save()
            messages.success(request,"TASK CREATED SUCCESSFULLY")
            return redirect('create-task')
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
            
    context={"task_form":task_form, "task_detail_form":task_detail_form}
    return render(request, "tasks.html", context)
def update_task(request, id):
    task_update=Task.objects.get(id=id)
    # employees=Employee.objects.all()
    task_form=TaskModelForm(instance=task_update)
    task_detail_form=TaskDetailForm(instance=task_update.details)
   
    if request.method=="POST":
        task_form=TaskModelForm(request.POST, instance=task_update)
        task_detail_form=TaskDetailForm(request.POST,instance=task_update.details)   
        if task_form.is_valid() and task_detail_form.is_valid():
            task=task_form.save()
            task_detail=task_detail_form.save(commit=False)
            task_detail.task=task         
            task_detail_form.save()
            messages.success(request,"TASK UPDATED SUCCESSFULLY")
            return redirect('update-task', id)
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
            
    context={"task_form":task_form, "task_detail_form":task_detail_form}
    return render(request, "tasks.html", context)

def delete_task(request, id):
    if request.method=='POST':
        task=Task.objects.get(id=id)
        task.delete()
        messages.success(request, 'Task Deleted Successfully')
        return redirect('manager-dashboard')
    else:
        messages.error(request, 'Something Went Wrong. Plese Try again...')
        return redirect('manager-dashboard')



def view_task(request):
    # tasks=Task.objects.all()
    employees=Employee.objects.prefetch_related('tasks').all()
    return render(request, "show_task.html", {"employees":employees})