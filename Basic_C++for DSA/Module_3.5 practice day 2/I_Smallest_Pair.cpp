#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n,mn=INT_MAX;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            mn=min(mn,a[i]+a[j]+j-i);
        }
        cout<<mn<<endl;
    }
    return 0;
}