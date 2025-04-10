#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt=0;
char building[1001][1001];
bool is_visit[1001][1001];
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool is_valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void DFS_2D(int si, int sj)
{
    is_visit[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + v[i].first;
        int cj = sj + v[i].second;
        if (is_valid(ci, cj) && !is_visit[ci][cj] && building[ci][cj] == '.')
        {
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
    vector<int>ve;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (building[i][j] == '.' && !is_visit[i][j])
            { 
                cnt=0;               
                DFS_2D(i, j);
                ve.push_back(cnt);
            }
        }
    }
    if(!ve.empty())
    sort(ve.begin(),ve.end());
    if(ve.empty()) cout<<"0";
    else
    for(int val: ve)
    cout<<val<<" ";
    return 0;
}