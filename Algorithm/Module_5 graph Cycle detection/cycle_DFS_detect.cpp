#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> graph[N];
int parent[N];
bool is_visit[N];
bool ans;
void DFS(int src)
{
    is_visit[src]=true;
    for(int child: graph[src])
    {
        if(is_visit[child] && child!=parent[src])
        {
            ans=true;
            return;
        }
        if(!is_visit[child])
        {
            // is_visit[child]=true;
            parent[child]=src;
            DFS(child);
        }
    }
    
}
int main()
{
    int n, e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(is_visit,false, sizeof(is_visit));
    memset(parent, -1, sizeof(parent));
    ans=false;
    for(int i=0;i<n;i++)
    {
        if(!is_visit[i])
        {
            DFS(i);
        }
    }
    if(ans) cout<<"Cycle Detected";
    else cout<<"Cycle Not Detected";
    return 0;
}