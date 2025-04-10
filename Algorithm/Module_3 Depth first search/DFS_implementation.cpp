#include<bits/stdc++.h>
using namespace std;
const int N=1e+5;
vector<int>graph[N];
bool is_visit[N];
void dfs_fun(int src)
{
    cout<<src<<" ";
    is_visit[src]=true;
    for(int i=0;i<graph[src].size();i++)
    {
        if(!is_visit[graph[src][i]])
        {
            dfs_fun(graph[src][i]);
        }        
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int src;
    cin>>src;
    dfs_fun(src);
    return 0;
}