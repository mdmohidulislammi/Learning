#include<bits/stdc++.h>
using namespace std;
class student
{
    public:
    char name[100];
    int clas;
    int roll;
};
int main()
{
    int n;
    cin>>n;
    //student a[n];
    //dynamic
    student *a=new student[n];
    for(int i=0;i<n;i++)
    {
        cin.ignore();
        cin.getline(a[i].name, 100);
        cin>>a[i].clas>>a[i].roll;
    } 
    for(int i=0;i<n;i++)
    {
        cout<<a[i].name<<" "<<a[i].clas<<" "<<a[i].roll<<endl;
    }
    return 0;
}