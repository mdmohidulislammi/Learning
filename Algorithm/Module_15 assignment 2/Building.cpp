#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u, v;
    long long int w;
    Edge(int u, int v, long long int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
const int N = 1e5 + 2;
int parent[N];
int sz[N];
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        sz[i] = 1;
    }
}
int f(int node)
{
    if (parent[node] == -1)
        return node;
    int lead = f(parent[node]);
    parent[node] = lead;
    return lead;
}
void us(int node1, int node2)
{
    int lead1 = f(node1);
    int lead2 = f(node2);
    if (sz[lead1] > sz[lead2])
    {
        parent[lead2] = lead1;
        sz[lead1] += sz[lead2];
    }
    else
    {
        parent[lead1] = lead2;
        sz[lead2] += sz[lead1];
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    init(n);
    vector<Edge> edgeList;
    while (e--)
    {
        int a, b;
        long long int c;
        cin >> a >> b >> c;
        edgeList.push_back(Edge(a, b, c));
    }
    sort(edgeList.begin(), edgeList.end(), cmp);
    long long int total = 0;
    for (Edge ed : edgeList)
    {
        int lead1 = f(ed.u);
        int lead2 = f(ed.v);
        if (lead1 != lead2)
        {
            us(ed.u, ed.v);
            total += ed.w;
        }
    }
    int connect=true;
    for(int i=1;i<=n;i++)
    {
        int lead1=f(1);
        int lead=f(i);
        if(lead!=lead1)
        connect=false;
    }
    if(connect) cout<<total;
    else cout<<-1;
    return 0;
}