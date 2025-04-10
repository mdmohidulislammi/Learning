#include <bits/stdc++.h>
using namespace std;
int n, m;
char graph_cell[1000][1000];
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
        if (is_valid(ci, cj) && !is_visit[ci][cj] && (graph_cell[ci][cj] == '.'))
        {
            DFS_2D(ci,cj);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> graph_cell[i][j];
    }
    memset(is_visit, false, sizeof(is_visit));
    int si,sj;
    cin>>si>>sj;
    DFS_2D(si,sj) ;
    int di, dj;
    cin>>di>>dj;
    if(is_visit[di][dj]) cout<<"YES";
    else cout<<"NO";   
    return 0;
}