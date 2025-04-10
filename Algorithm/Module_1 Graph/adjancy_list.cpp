#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int> mat_list[n];
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        mat_list[a].push_back(b);
        mat_list[b].push_back(a);
    }
    for(int i=0;i<mat_list[0].size();i++)
    cout<<mat_list[0][i]<<" ";
    cout<<endl;
    for(int val: mat_list[0])
    cout<<val<<" ";
    return 0;
}