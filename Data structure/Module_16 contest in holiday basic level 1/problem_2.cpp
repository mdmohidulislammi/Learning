#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        v.push_back(value);
    }
    reverse(v.begin(),v.end());
    vector<int>a(v.size());
    a[0]=0;
    for(int i=1;i<a.size();i++)
    {
        a[i]=a[i-1]+v[i-1];
    }
    for(int i=a.size()-1;i>=0;i--)
    cout<<a[i]<<" ";
    // int a[v.size()];
    // a[0]=0;
    // for(int i=1;i<=v.size();i++)
    // {
    //     a[i]=a[i-1]+v[i-1];
    // }
    // for(int i=v.size()-1;i>=0;i--)
    // cout<<a[i]<<" ";
    return 0;
}