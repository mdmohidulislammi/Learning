#include <bits/stdc++.h>
using namespace std;
int n, m;
int di,dj;
bool is_visit[101][101];
int dis[101][101];
vector<pair<int, int>> v = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
bool is_valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void bfs_2D(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    is_visit[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int ci = par.first + v[i].first;
            int cj = par.second + v[i].second;
            if (is_valid(ci, cj) && (!is_visit[ci][cj]))
            {
                q.push({ci, cj});
                is_visit[ci][cj] = true;
                dis[ci][cj] = dis[par.first][par.second] + 1;
            }
        }
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int si, sj;
        cin >> n >> m;
        cin >> si >> sj;
        cin >> di >> dj;
        memset(is_visit,false, sizeof(is_visit));
        memset(dis,-1,sizeof(dis));
        bfs_2D(si,sj);        
        cout<<dis[di][dj]<<endl;
    }
    return 0;
}