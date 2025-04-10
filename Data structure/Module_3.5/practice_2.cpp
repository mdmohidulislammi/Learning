#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int>prefix_sum(n);
    prefix_sum[0]=v[0];
    for(int i=1;i<prefix_sum.size();i++)
    {
        prefix_sum[i]=prefix_sum[i-1]+v[i];
    }
    bool flag=false;
    for(int i=0;i<prefix_sum.size();i++)
    {
        if(prefix_sum[i-1]==prefix_sum[prefix_sum.size()-1]-prefix_sum[i])
        cout<<i<<endl;
    }
    return 0;
}