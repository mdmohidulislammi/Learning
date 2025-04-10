#include<bits/stdc++.h>
using namespace std;
class student 
{
    public:
    char name[100];
    int clas;
    int roll;
    int marks;

};
int main()
{
    int n;
    cin>>n;
    student a[n],mn,mx;
    mn.marks=INT_MAX;
    mx.marks=INT_MIN;
     for(int i=0;i<n;i++)
     {
        getchar();
       cin.getline(a[i].name,100);
        cin>>a[i].clas>>a[i].roll>>a[i].marks;
     }
     for(int i=0;i<n;i++)
     {
         if(a[i].marks<mn.marks)
         {
            mn=a[i];
         }
         if(a[i].marks>mx.marks)
         {
            mx=a[i];
         }
     }
     cout<<mn.name<<" "<<mn.clas<<" "<<mn.roll<<" "<<mn.marks<<endl;
     cout<<mx.name<<" "<<mx.clas<<" "<<mx.roll<<" "<<mx.marks<<endl;
}