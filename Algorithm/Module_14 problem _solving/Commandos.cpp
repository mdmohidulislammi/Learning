#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int> v[N];
bool vis[N];
int src_dis[N];
int des_dis[N];
void bfs(int src, int track)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    if (track == 1)
        src_dis[src] = 0;
    else if(track==2)
        des_dis[src] = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int val : v[parent])
        {
            if (!vis[val])
            {
                if (track == 1)
                    src_dis[val] = src_dis[parent] + 1;
                else if(track==2)
                    des_dis[val] = des_dis[parent] + 1;
                vis[val] = true;
                q.push(val);
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    int j = 1;
    while (j <= t)
    {
        int n, e;
        cin >> n >> e;
        while (e--)
        {
            int a, b;
            cin >> a;
            cin >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int s, d;
        cin >> s >> d;
        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
            src_dis[i] = -1;
        }
        bfs(s, 1);
        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
            des_dis[i] = -1;
        }
        bfs(d, 2);
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int value = src_dis[i] + des_dis[i];
            ans = max(ans, value);
        }
        cout << "Case " << j << ": " << ans << endl;
        j++;
        for (int i = 0; i < n; i++)
        {
            v[i].clear();
        }
        break;
    }
    return 0;
}
