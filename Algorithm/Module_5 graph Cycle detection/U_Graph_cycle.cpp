#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool is_vis[N];
vector<int>cycle_graph[N];
bool ans;
int par[N];
void bfs(int s)
{
     queue<int> q;
     q.push(s);
     is_vis[s]=true;
     while(!q.empty())
     {
        int parent=q.front();
        q.pop();
        for(int child: cycle_graph[parent])
        {
            if(is_vis[child] && par[parent]!=child)
            {
                ans=true;
            }
            
            // cout<<"Not found cycle"<<endl;
            if(!is_vis[child])
            {
                is_vis[child]=true;
                q.push(child);
                par[child]=parent;
            }
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
        cycle_graph[a].push_back(b);
        cycle_graph[b].push_back(a);
    }
    memset(is_vis, false, sizeof(is_vis));
    memset(par, -1, sizeof(par));
    ans=false;
    for(int i=0;i<n;i++)
    {
        if(!is_vis[i])
        {
            bfs(i);
        }
    }   
    if(ans) cout<<"Cycle found"<<endl;
    else cout<<"Cycle Not found"<<endl; 
    return 0;
}