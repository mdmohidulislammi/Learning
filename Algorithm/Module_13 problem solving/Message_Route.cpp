#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
vector<int> graph[N];
bool vis[N];
int parent[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src]=true;
    while(!q.empty())
    {
        int par=q.front();
        q.pop();
        for(int child: graph[par])
        {
            if(!vis[child])
            {
                vis[child]=true;
                parent[child]=par;
                q.push(child);
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }    
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    bfs(1);
    int minimun=0;
    vector<int> path;
    int st=n;
    if(!vis[n])
    {
        cout<<"IMPOSSIBLE";
    }
    else 
    {
        while(st!=-1)
        {
            path.push_back(st);
            st=parent[st];
            minimun++;
        }
        reverse(path.begin(),path.end());
        cout<<minimun<<endl;
        for(int val: path)
        cout<<val<<" ";
    }
    return 0;
}