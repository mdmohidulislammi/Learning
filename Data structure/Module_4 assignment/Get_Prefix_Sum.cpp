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
    vector<long long int>pre_sum(n);
    pre_sum[0]=v[0];
    for(int i=1;i<pre_sum.size();i++)
    {
      pre_sum[i]=pre_sum[i-1]+v[i];
    }
    reverse(pre_sum.begin(),pre_sum.end());
    for(int i=0;i<pre_sum.size();i++)
    {
        cout<<pre_sum[i]<<" ";
    }
    return 0;
}