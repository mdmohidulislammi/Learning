#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,mn=INT_MAX;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        mn=min(mn,a[i]);
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==mn)
        cnt++;
    }
    if(cnt%2==0)
    cout<<"Unlucky";
    else
    cout<<"Lucky";
    return 0;
}