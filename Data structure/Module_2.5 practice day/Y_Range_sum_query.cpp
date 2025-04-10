#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin>>n>>t;
    vector<int>v(n);
    for(int i=1;i<=v.size();i++)
    {
        cin>>v[i];
    }
    // for(int i=1;i<v.size();i++)
    // cout<<v[i]<<" ";
    for(int i=1;i<=t;i++)
    {
        int l,r;
        long long int sum=0;
        cin>>l>>r;
        for(int j=l;j<=r;j++)
        {
           // if(j>=l && r>=j)
            sum=sum+v[j];
        }
        cout<<sum<<endl;
        
    }
    return 0;
}