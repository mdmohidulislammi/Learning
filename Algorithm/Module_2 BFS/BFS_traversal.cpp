#include <bits/stdc++.h>
using namespace std;
vector<int> vis[1005];
bool bfs[1005];
void BFS_traverse(int src)
{
    queue<int> q;
    q.push(src);
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
    return 0;
}