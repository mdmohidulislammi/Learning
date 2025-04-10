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
    int b;
    cin>>b;
    vector<int>v1(b);
    for(int i=0;i<v1.size();i++)
    {
        cin>>v1[i];
    }
    int target_index;
    cin>>target_index;
    v.insert(v.begin()+target_index,v1.begin(),v1.end());
    for(int elements:v)
    {
        cout<<elements<<" ";
    }
    return 0;
}