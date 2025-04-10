#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100005];
bool is_visit[100005];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    is_visit[src]=true;
    while(!q.empty())
    {
        int par=q.front();
        q.pop();
        for(int child: graph[par])
        {
            if(!is_visit[child])
            {
                q.push(child);
                is_visit[child]=true;
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
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(is_visit,false, sizeof(is_visit));
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(!is_visit[i])
        {
            bfs(i);
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}