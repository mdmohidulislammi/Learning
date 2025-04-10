#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 1;
int n, m;
bool vis[N][N];
char graph[N][N];
int mn = INT_MAX;
int area;
vector<pair<int,int> > v={{1,0},{-1,0},{0,1},{0,-1}};
bool valid(int i, int j)
{
    if (i >= 1 && j >= 1 && i <= n && j <= m)
        return true;
    else
        return false;
}
void dfs(int si, int sj)
{
    vis[si][sj]=true;
    area++;
    for(int i=0;i<4;i++)
    {
        int ci=si+v[i].first;
        int cj=sj+v[i].second;
        if(valid(ci,cj) && !vis[ci][cj] && graph[ci][cj]=='.')
        dfs(ci,cj);
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
    bool ans=false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!vis[i][j] && graph[i][j] == '.')
            {
                area=0;
                dfs(i, j);
                if(area!=0)
                mn=min(mn,area);
                ans=true;
            }
        }
    }
    if(ans) cout<<mn;
    else cout<<-1;
    return 0;
}