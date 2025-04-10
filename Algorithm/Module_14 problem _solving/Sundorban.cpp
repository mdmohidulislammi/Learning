#include <bits/stdc++.h>
using namespace std;
char graph[50][50];
int dis[50][50];
int n;
bool vis[50][50];
vector<pair<int, int> > v;
bool valid(int si, int sj)
{
    if (si >= 0 && si < n && sj >= 0 && sj < n)
        return true;
    else
        return false;
}
void bfs(int si, int sj)
{
    queue<pair<int, int> > q;
    q.push({si, sj});
    dis[si][sj] = 0;
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = parent.first + v[i].first;
            int cj = parent.second + v[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && graph[ci][cj] != 'T')
            {
                vis[ci][cj] = true;
                dis[ci][cj] = dis[parent.first][parent.second] + 1;
                q.push({ci, cj});
            }
        }
    }
}
int main()
{
    v.push_back({1, 0});
    v.push_back({-1, 0});
    v.push_back({0, 1});
    v.push_back({0, -1});
    while (cin >> n)
    {
        int si = 0, sj = 0, di = 0, dj = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> graph[i][j];
                if (graph[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                else if (graph[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        bfs(si, sj);
        cout << dis[di][dj];
    }

    return 0;
}