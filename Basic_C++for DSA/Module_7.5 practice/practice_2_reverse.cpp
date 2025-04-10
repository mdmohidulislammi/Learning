#include<bits/stdc++.h>
using namespace std;
class student
{
    public:
    string name;
    int roll;
    int mark;

};
int main()
{
    int n;
    cin>>n;
    student a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].name>>a[i].roll>>a[i].mark;
    }
    int j=n-1;
    for(int i=0;i<j;i++)
    {
       student t=a[i];
       a[i]=a[j];
       a[j]=t;
       j--;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i].name<<" "<<a[i].roll<<" "<<a[i].mark<<endl;
    }
    return 0;
}