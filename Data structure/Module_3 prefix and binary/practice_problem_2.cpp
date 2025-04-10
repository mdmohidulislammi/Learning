#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<v.size();i++)
    {
        cin>>v[i];
    }
    vector<int>v1(n);
    v1[0]=0;
    for(int i=1;i<v1.size();i++)
    {
        v1[i]=v[i-1]+v1[i-1];
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v1[i]<<" ";
    }
    return 0;
}