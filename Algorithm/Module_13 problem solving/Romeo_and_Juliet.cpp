#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int> graph[N];
int dis[N];
int des[N];
bool vis[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;
    des[src] = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int child : graph[parent])
        {
            if (!vis[child])
            {
                vis[child] = true;
                des[child] = parent;
                dis[child] = dis[parent] + 1;
                q.push(child);
            }
        }
    }
}
int main()
{
    int n,e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(dis, -1, sizeof(dis));
    memset(vis, false, sizeof(vis));
    memset(des, -1, sizeof(des));
    int src, dest, k;
    cin >> src >> dest >> k;
    bfs(src);
    if (dis[dest] != -1 && dis[dest] <= (k * 2))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}