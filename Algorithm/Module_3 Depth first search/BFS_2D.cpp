#include <bits/stdc++.h>
using namespace std;
int n, m;
char graph[20][20];
bool is_visit[20][20];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int des[20][20];
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    else
        return true;
}
void bfs_2D(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    is_visit[si][sj] = true;
    des[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        cout << par.first << " " << par.second << endl;
        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;
            if (valid(ci, cj) && (!is_visit[ci][cj]))
            {
                q.push({ci, cj});
                is_visit[ci][cj] = true;
                des[ci][cj] = des[par.first][par.second] + 1;
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
            cin >> graph[i][j];
    }

    memset(is_visit, false, sizeof(is_visit));
    memset(des, -1, sizeof(des));
    int si, sj;
    cin >> si >> sj;
    bfs_2D(sj, sj);
    cout<<des[2][3];
    return 0;
}