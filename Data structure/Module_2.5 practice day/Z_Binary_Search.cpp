#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin>>n>>t;
    vector<int>v(n);
    for(int i=0;i<v.size();i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<t;i++)
    {
        int s;
        cin>>s;
        auto it=find(v.begin(),v.end(),s);
        if(it!=v.end()) cout<<"found"<<endl;
        else
        cout<<"not found"<<endl;
    }
    return 0;
}