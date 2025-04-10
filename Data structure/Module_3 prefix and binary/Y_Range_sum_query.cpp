#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,t;
    cin>>n>>t;
    long long a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long pre[n];
    pre[0]=a[0];
    for(int i=1;i<n;i++)
    {
        pre[i]=a[i]+pre[i-1];
    }
    //  for(int i=0;i<n;i++)
    // {
    //     cout<<pre[i]<<" ";
    // }
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        if(l==0) cout<<pre[r]<<endl;
        else
        cout<<pre[r]-pre[l-1]<<endl;
    }
    return 0;
}
    //TLE
    // int n,t;
    // cin>>n>>t;
    // int a[n];
    // for(int i=0;i<n;i++)
    // {
    //     cin>>a[i];
    // }
    // for(int i=0;i<t;i++)
    // {
    //     int l,r;
    //     cin>>l>>r;
    //     long long int s=0;
    //     for(int j=l-1;j<=r-1;j++)
    //    {
    //     s=s+a[j];
    //    }
    //  cout<<s<<endl;
//     // }
//     return 0;
// }