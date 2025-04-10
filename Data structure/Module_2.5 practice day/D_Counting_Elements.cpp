#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cnt=0;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<v.size();i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<v.size();i++)//for(int i=0;i<v.size()-1;i++)
    {
        auto it=find(v.begin(),v.end(),v[i]+1);
        if(it!=v.end())
        cnt++;
        // for(int j=0;j<v.size();j++)
        // if(v[i]+1==v[j])
        // cnt++;
    }
    cout<<cnt;
    return 0;
}