#include <bits/stdc++.h>
using namespace std;
int n, m;
char building[1000][1000];
bool is_visit[1000][1000];
int flag;
vector<pair<int, int>> dist = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool is_valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    else
        return true;
}
void DFS_2D(int si, int sj)
{
    is_visit[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + dist[i].first;
        int cj = sj + dist[i].second;
        if (is_valid(ci, cj) && !is_visit[ci][cj] && (building[ci][cj] == '.' || building[ci][cj] == 'B'))
        {
            if (building[ci][cj] == 'B')
            {
                is_visit[ci][cj] = true;
                flag = 1;
                return;
            }
            else
                DFS_2D(ci, cj);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> building[i][j];
    }
    memset(is_visit, false, sizeof(is_visit));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (building[i][j] == 'A')
            {
                flag = 0;
                DFS_2D(i, j);
                if (flag == 1)
                    cout << "YES";
                else
                    cout << "NO";
                break;
            }
        }
    }
    return 0;
}