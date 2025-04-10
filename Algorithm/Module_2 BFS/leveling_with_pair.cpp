#include <bits/stdc++.h>
using namespace std;
vector<int> vis[1005];
bool bfs[1005];
void BFS_traverse(int src,int des)
{
    queue<pair<int,int>> q;
    q.push({src,0});
    bfs[src] = true;
    while (!q.empty())
    {
      pair<int,int> par= q.front();
        q.pop();
       int parent=par.first;
       int level=par.second;
       if(parent==des)cout<<level;
        for (int child : vis[parent])
        {
            if (!bfs[child])
            {
                q.push({child,level+1});
                bfs[child] = true;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        vis[a].push_back(b);
        vis[b].push_back(a);
    }
    int src;
    cin >> src;
    memset(bfs, false, sizeof(bfs));
    BFS_traverse(src,5);
    return 0;
}