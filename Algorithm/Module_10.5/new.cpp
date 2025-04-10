#include <bits/stdc++.h>
using namespace std;
bool vis[1001][1001];
vector<pair<int, int>> v = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
string path;
int shortest_path;
char graph[1001][1001];
int n, m;
bool valid(int i, int j)
{
    if (i >= 0 && j >= 0 && i < n && j < m)
        return true;
    else
        return false;
}
void bfs(int si, int sj)
{
    vis[si][sj] = true;
    queue<pair<int, int>> q;
    q.push({si, sj});
    while (!q.empty())
    {
        pair<int, int> paren = q.front();
        q.pop();
        int pi = paren.first;
        int pj = paren.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = pi + v[i].first;
            int cj = pj + v[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                if (graph[ci][cj] == '.')
                {
                    vis[ci][cj] = true;

                    if (i == 0)
                        path += 'D';
                    else if (i == 1)
                        path += 'U';
                    else if (i == 2)
                        path += 'R';
                    else if (i == 3)
                        path += 'L';
                    shortest_path++;
                    q.push({ci, cj});
                }
                else if (graph[ci][cj] == 'B')
                    return;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    shortest_path = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 'A')
            {
                bfs(i, j);
                break;
            }
        }
    }
    if (shortest_path == 0)
        cout << "NO";
    else
        cout << "YES" << endl
             << shortest_path << endl
             << path;
    return 0;
}