#include <bits/stdc++.h>
using namespace std;
vector<int> graph[10005];
bool ans[10005];
int level[10005];
int path[10005];
void destination_find(int src)
{
    queue<int> q;
    q.push(src);
    ans[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int val : graph[par])
        {
            if (!ans[val])
            {
                q.push(val);
                ans[val] = true;
                level[val] = level[par] + 1;
                path[val] = par;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        memset(ans, false, sizeof(ans));
        memset(path, -1, sizeof(path));
        int src, des;
        cin >> src >> des;
        vector<int> short_path;
        destination_find(src);  
        int x = des;
        int cnt=0;
        while (path[x] != -1)
        {
            short_path.push_back(x);
            cnt++;
            x = path[x];
        }
        if(short_path.empty())cout<<"-1"<<endl;
        else cout<<cnt<<endl;
        
    }
    return 0;
}