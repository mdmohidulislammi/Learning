#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> v = {{-1, 1}, {-1, -1}, {1, -1}, {1, 1}};
int graph[1005][1005];
bool vis[1005][1005];
pair<int, int> parent[1005][1005];
bool valid(int ci, int cj)
{
    return (ci >= 0 || cj >= 0 || ci < n || cj < m);
}
int di,dj;
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    parent[si][sj] = {0, 0};
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + v[i].first;
            int cj = par.second + v[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && graph[ci][cj] != 0)
            {
                
                parent[ci][cj] = {par.first, par.second};
                vis[ci][cj] = true;
                if(di==ci && cj==dj) break;
                
                q.push({ci, cj});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int w = 1;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> graph[i][j];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = false;
                parent[i][j] = {-1, -1};
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (graph[i][j] == -1)
                    bfs(i, j);
                else if (graph[i][j] == -2)
                {
                    di = i;
                    dj = j;
                }
            }
        }
        long long cnt = 0;
        pair<int, int> p = {parent[di][dj].first, parent[di][dj].second};
        while (p.first != -1 && p.second != -1)
        {
            cnt += graph[p.first][p.second];
            p = parent[p.first][p.second];
        }
        if (vis[di][dj])
            cout << "Case " << w << ": " << cnt << endl;
        else
            cout << "Case " << w << ": Impossible" << endl;

        w++;
    }
    return 0;
}