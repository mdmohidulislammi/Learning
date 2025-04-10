#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e9 + 1;
vector<pair<int, long long int>> graph[1001];
long long dis[1001];
class cmp
{
public:
    bool operator()(pair<int, long long int> a, pair<int, long long int> b)
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
    priority_queue<pair<int, long long int>, vector<pair<int, long long int>>, cmp> q;
    q.push({src, 0});
    dis[src] = 0;
    while (!q.empty())
    {
        pair<int, long long int> parent = q.top();
        q.pop();
        int parentNode = parent.first;
        long long int parentCost = parent.second;
        for (pair<int, long long int> child : graph[parentNode])
        {
            int childNode = child.first;
            long long int childCost = child.second;
            if (childCost + parentCost < dis[childNode])
            {
                dis[childNode] = childCost + parentCost;
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
        int a, b;
        long long int c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    int src;
    cin >> src;
    dijkstra(src);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int des;
        long long int cost;
        cin >> des >> cost;
        if (dis[des] <= cost)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}