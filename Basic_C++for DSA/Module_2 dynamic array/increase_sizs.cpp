#include<bits/stdc++.h>
using namespace std;
int main()
{
    int *a= new int [5];
    int *b=new int [5];
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }    
    delete[] a;
    a=new int [6];
    for(int i=0;i<6;i++)
{
    a[i]=b[i];
}
a[5]=23;
delete[] b;
for(int i=0;i<6;i++)
{
    cout<<a[i]<<" ";
}
    return 0;
}