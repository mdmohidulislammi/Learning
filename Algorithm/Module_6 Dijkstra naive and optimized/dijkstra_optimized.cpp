#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<pair<int, int>> graph[N];
int dis[N];
class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.second > b.second)
        {
            return true;
        }
        else
            return false;
    }
};
void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q; // queue<pair<int,int>>q;
    q.push({src, 0});
    dis[src] = 0;
    while (!q.empty())
    {
        pair<int, int> parent = q.top();
        q.pop();
        int parentNode = parent.first;
        int parentCost = parent.second;
        // cout<<parentCost<<" -> "<<parentNode<<" ";
        // cout<<dis[parentNode]<<" "<<endl;;
        for (pair<int, int> child : graph[parentNode])
        {
            int childNode = child.first;
            int childCost = child.second;
            if (childCost + dis[parentNode] < dis[childNode])
            {
                dis[childNode] = childCost +dis[parentNode];
                q.push({childNode, dis[childNode]});
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
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << i << " ->>" << dis[i] << endl;
    }
    return 0;
}