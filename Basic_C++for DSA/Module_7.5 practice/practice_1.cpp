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
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i].mark<a[j].mark)
            {
                student t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
            else if(a[i].mark==a[j].mark)
            {
                if(a[i].roll>a[j].roll)
                {
                    student t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }        
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i].name<<" "<<a[i].roll<<" "<<a[i].mark<<endl;
    }
    return 0;
}