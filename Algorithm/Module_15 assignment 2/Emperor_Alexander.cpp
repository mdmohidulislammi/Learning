#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class Edge
{
public:
    int u, v;
    ll w;
    Edge(int u, int v, ll w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.w< b.w;
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
int find(int node)
{
    if (parent[node] == -1)
        return node;
    int lead = find(parent[node]);
    parent[node] = lead;
    return lead;
}
void union_s(int node1, int node2)
{
    int lead1 = find(node1);
    int lead2 = find(node2);
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
        ll c;
        cin>>a>>b>>c;
        edgeList.push_back(Edge(a,b,c));
    }
    int close=0;
    ll total=0;
    sort(edgeList.begin(),edgeList.end(),cmp);
    for(Edge ed: edgeList)
    {
        int leadA=find(ed.u);
        int leadB=find(ed.v);
        if(leadA==leadB)
        close++;
        else 
        {
          union_s(ed.u,ed.v);
          total+=ed.w;
        }

    }
    bool connect=true;
    for(int i=1;i<=n;i++)
    {
        int lead1=find(1);
        int lead=find(i);
        if(lead!=lead1)
        connect=false;
    }
    if(connect) cout<<close<<" "<<total;
    else cout<<"Not Possible";
    return 0;
}