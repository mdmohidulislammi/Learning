#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            if (i<n-1)
            {
            if(a[i]!=a[i+1])
            cout<<a[i]<<" ";
            }
            else cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}