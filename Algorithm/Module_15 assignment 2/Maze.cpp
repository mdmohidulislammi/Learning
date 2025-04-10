#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int n, m;
bool vis[N][N];
pair<int, int> parent[N][N];
char graph[N][N];
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    if (i >= 1 && j >= 1 && i <= n && j <= m)
        return true;
    else
        return false;
}
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
            if (valid(ci, cj) && !vis[ci][cj] && graph[ci][cj] != '#')
            {
                vis[ci][cj] = true;
                parent[ci][cj] = {par.first, par.second};
                q.push({ci, cj});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> graph[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    int si, sj, di, dj;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (graph[i][j] == 'R')
            {
                si = i, sj = j;
                bfs(i, j);
            }
            else if (graph[i][j] == 'D')
                di = i, dj = j;
        }
    }
    if (vis[di][dj])
    {
        pair<int, int> start = {parent[di][dj].first, parent[di][dj].second};
        while (start.first != si || start.second != sj) // while(parent[start.first][start.second].first!=0 && parent[start.first][start.second].second!=0)
        {
            graph[start.first][start.second] = 'X';
            start = {parent[start.first][start.second].first, parent[start.first][start.second].second};
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << graph[i][j];
        }
        cout << endl;
    }
    return 0;
}