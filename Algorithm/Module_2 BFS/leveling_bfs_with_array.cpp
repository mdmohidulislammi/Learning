#include <bits/stdc++.h>
using namespace std;
vector<int> vis[1005];
int level[1005];
bool bfs[1005];
void BFS_traverse(int src)
{
    queue<int> q;
    q.push(src);
    level[src]=0;
    bfs[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << endl;

        for (int child : vis[par])
        {
            if (!bfs[child])
            {
                q.push(child);
                bfs[child] = true;
                level[child]=level[par]+1;
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
    BFS_traverse(src);
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<level[i]<<endl;
    }
    return 0;
}