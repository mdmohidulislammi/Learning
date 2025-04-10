#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e18;
long long int dis[1001];
class edge
{
public:
    int u, v;
    long long int c;
    edge(int u, int v, long long int c)
    {
        this->c = c;
        this->u = u;
        this->v = v;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<edge> edgeList;
    while (e--)
    {
        int a, b;
        long long int c;
        cin >> a >> b >> c;
        edgeList.push_back(edge(a, b, c));
    }
    for (int i = 1; i <=n; i++)
    {
        dis[i] = N;
    }
    int src;
    cin >> src;
    dis[src] = 0;
    for (int i = 0; i < n; i++)
    {
        for (edge ed : edgeList)
        {
            int u = ed.u, v = ed.v;
            long long int c = ed.c;
            if (dis[u] < N && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    bool ans = false;
    for (edge ed : edgeList)
    {
        int u = ed.u, v = ed.v;
        long long int c = ed.c;
        if (dis[u] < N && dis[u] + c < dis[v])
        {
            ans = true;
        }
    }
    if (ans)
    {
        cout << "Negative Cycle Detected";
    }
    else
    {
        int test;
        cin >> test;
        for (int i = 0; i < test; i++)
        {
            int des;
            cin >> des;
            if (dis[des] ==N)
                cout << "Not Possible";
            else
                cout << dis[des];
            cout << endl;
        }
    }
    return 0;
}