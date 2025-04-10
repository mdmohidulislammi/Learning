#include<bits/stdc++.h>
using namespace std;
class student
{
    public:
    char name[100];
    int cls;
    int roll;
    int mark;
};
bool cmp(student a, student b)
{
  /*// if(a.mark>=b.mark) return true;
   //else return false;
   //same 
    //return a.mark>=b.mark;*/
   /* if(a.mark > b.mark)
    {
        return true;
    }
    else if(a.mark<b.mark)
    {
        return false;
    }
    else
    {
        return a.roll<b.roll;
    }*/
    if(a.mark==a.mark)
    {
        return a.roll<b.roll;
    }
    else
    {
        return a.mark>b.mark;
    }
}
int main()
{
    int n;
    cin>>n;
    student a[n];
    for(int i=0;i<n;i++)
    {
        getchar();
        cin.getline(a[i].name, 100);
        cin>>a[i].cls>>a[i].roll>>a[i].mark;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<a[i].name<<" "<<a[i].cls<<" "<<a[i].roll<<" "<<a[i].mark<<endl;
    }
    return 0;
}