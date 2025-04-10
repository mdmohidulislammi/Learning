#include<bits/stdc++.h>
using namespace std;
vector<int> adjacent_small(vector <int>& v)
{
   vector<int>ve;
   for(int i=0;i<v.size();i++)
   {
      if(i!=0 && i!=v.size()-1)
      {
        if(v[i+1]>v[i] && v[i-1]>v[i])
        ve.push_back(v[i]);
      }
   }
   return ve;
}
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
   vector<int>ve=adjacent_small(v);
   for(int i=0;i<ve.size();i++)
   cout<<ve[i]<<endl;
    return 0;
}