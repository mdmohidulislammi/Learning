#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        vector<int>v(n),v1(n);
        for(int i=0;i<v.size();i++)
        {
            cin>>v[i];
            v1[i]=v[i];
        }
        bool flag=true;
        sort(v.begin(),v.end());
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]!=v[i])
            flag=false;
        }
       if(flag==true) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;       
    }
    return 0;
}