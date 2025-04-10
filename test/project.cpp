#include <bits/stdc++.h>
using namespace std;
class student
{
public:
    string name, dept;
    int roll, marks;
    char section, cls[4];
    // student(string name, const char *cls, char section, string dept, int roll, int marks)
    // {
    //     this->name = name;
    //     strcpy(this->cls, cls);
    //     this->section = section;
    //     this->dept = dept;
    //     this->roll = roll;
    //     this->marks = marks;
    // }
};
class cmp
{
public:
    bool operator()(student a, student b)
    {
        if(a.marks<b.marks)
        return true;
        else if(a.marks==b.marks)
        {
            if(a.roll>b.roll)
            return true;
        }
    }
};
int main()
{
    int n;
    cin>>n;
    priority_queue<student,vector<student>,cmp>pq;
    student *a=new student[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].name>>a[i].cls>>a[i].section>>a[i].dept>>a[i].roll>>a[i].marks;

        pq.push(a[i]);
    }    
    while(!pq.empty())
    {
        cout<<pq.top().name<<" "<<pq.top.cls<<" "<<pq.top.
    }
    return 0;
}