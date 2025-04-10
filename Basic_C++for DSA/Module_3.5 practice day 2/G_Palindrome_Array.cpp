#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    int j=n-1;
    for(int i=0;i<j;i++)
    {
        int t=b[i];
        b[i]=b[j];
        b[j]=t;
        j--;
    }
    int p=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        p=1;
    }
    if(p==0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}