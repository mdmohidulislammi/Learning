#include <bits/stdc++.h>
using namespace std;
bool vis[1020][1020];
vector<pair<int, int>> v = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
string path[1020][1020];
int shortest_path[1020][1020];
char graph[1020][1020];
int n, m;
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
    shortest_path[si][sj] = 0;
    vis[si][sj] = true;
    q.push({si, sj});
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int pi = parent.first;
        int pj = parent.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = pi + v[i].first;
            int cj = pj + v[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && graph[ci][cj] != '#')
            {
                if (i == 0)
                {

                    path[ci][cj] = path[pi][pj] + 'D';
                }
                else if (i == 1)
                {

                    path[ci][cj] = path[pi][pj] + 'U';
                }
                else if (i == 2)
                {

                    path[ci][cj] = path[pi][pj] + 'R';
                }
                else if (i == 3)
                {

                    path[ci][cj] = path[pi][pj] + 'L';
                }
                vis[ci][cj] = true;
                shortest_path[ci][cj] = shortest_path[pi][pj] + 1;
                q.push({ci, cj});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int di=0,dj=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> graph[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    memset(shortest_path, -1, sizeof(shortest_path));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (graph[i][j] == 'A')
            {
                bfs(i, j);
            }
            else if (graph[i][j] == 'B')
                di = i, dj = j;
        }
    }
    if (vis[di][dj])
    {
        cout << "YES" << endl
             << shortest_path[di][dj] << endl
             << path[di][dj];
    }
    else
        cout << "NO";
    return 0;
}