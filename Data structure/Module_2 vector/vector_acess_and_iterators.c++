#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v={1,2,3,4,4,5};
    cout<<v[v.size()-2]<<endl;
    cout<<v.back()<<endl;
    cout<<v[0]<<endl;
    for(auto it=v.begin();it<v.end();it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}