#include<bits/stdc++.h>
using namespace std;
vector<int> fun(vector<int>&v)
{
    vector<int>running_sum(v.size());
    running_sum[0]=v[0];
    for(int i=1;i<running_sum.size();i++)
    {
        running_sum[i]=v[i]+running_sum[i-1];
    }
    for(int c:running_sum)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    return running_sum;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<v.size();i++)
    {
        cin>>v[i];
    }
  vector<int>ans=  fun(v);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}