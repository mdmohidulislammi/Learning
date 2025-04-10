#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int dis[N];
class edge
{
public:
    int u, v, c;
    edge(int u, int v, int c)
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
        int a, b, c;
        cin >> a >> b >> c;
        edgeList.push_back(edge(a, b, c));
    }
    // for(edge ed: edgeList)
    // {
    //     cout<<ed.u<<" "<<ed.v<<" "<<ed.c<<endl;
    // }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (edge ed : edgeList)
        {
            int u = ed.u, v = ed.v, c = ed.c;
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    bool ans = false;
    for (edge ed : edgeList)
    {
        int u = ed.u, v = ed.v, c = ed.c;
        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            ans = true;
            break;
        }
    }
    if (ans)
        cout << "cycle found . No answer" << endl;
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " -->>" << dis[i] << endl;
        }
    }
    return 0;
}o