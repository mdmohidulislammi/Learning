#include <bits/stdc++.h>
using namespace std;
bool vis[1020][1020];
vector<pair<int, int>> v = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int shortest_path[1020][1020];
pair<int,int>  parent[1020][1020];
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
        pair<int, int> par = q.front();
        q.pop();
        int pi = par.first;
        int pj = par.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = pi + v[i].first;
            int cj = pj + v[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && graph[ci][cj] != '#')
            {
                vis[ci][cj] = true;
                parent[ci][cj]=par;
                shortest_path[ci][cj] = shortest_path[pi][pj] + 1;
                q.push({ci, cj});
            }
        }
    }
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cin >> n >> m;
    int di=0,dj=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> graph[i][j];
        }
    }
    int si,sj;
    memset(vis, false, sizeof(vis));
    memset(shortest_path, -1, sizeof(shortest_path));
    memset(parent,-1, sizeof(parent));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (graph[i][j] == 'A')
            {
                si=i,sj=j;
                bfs(i, j);
            }
            else if (graph[i][j] == 'B')
                di = i, dj = j;
        }
    }
    if (vis[di][dj])
    {
        cout << "YES" << endl
             << shortest_path[di][dj] << endl;
            pair<int,int> p={di,dj};
            vector<pair<int,int>> path;
            while(!(p.first==si && p.second==sj))
            {
                 path.push_back(p);
                 p=parent[p.first][p.second];
            }
            path.push_back({si,sj});
            reverse(path.begin(),path.end());
            string ans="";
            for(int i=1;i<path.size();i++)
            {
                if(path[i-1].first==path[i].first) // R or L 
                {
                    if(path[i-1].second+1==path[i].second)
                    ans+="R";
                    else ans+="L";
                }
                else
                {
                    if(path[i-1].first+1==path[i].first)
                    ans+="D";
                    else ans+="U";
                }
            }
            cout<<ans;
    }
    else
        cout << "NO";
    return 0;
}