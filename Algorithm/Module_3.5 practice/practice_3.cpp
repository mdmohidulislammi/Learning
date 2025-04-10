#include <bits/stdc++.h>
using namespace std;
vector<int> graph[10005];
int cnt = 0;
bool is_visit[10005];
int DFS(int src)
{

    is_visit[src] = true;
    cnt++;
    for (int val : graph[src])
    {
        if (!is_visit[val])
            DFS(val);
    }
    return cnt;
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
    memset(is_visit, false, sizeof(is_visit));
    vector<int>v;

    for (int i = 0; i < n; i++)
    {
        if (!is_visit[i])
        {
            int c = DFS(i);
            v.push_back(c);
            
        }
        cnt=0;
    }
    sort(v.begin(),v.end());
    for(int val: v) cout<<val<<" ";
    return 0;
}