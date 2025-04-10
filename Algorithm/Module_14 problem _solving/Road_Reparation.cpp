#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int parent[N];
int group_size[N];
class Edge
{
    public:
     int u,v;
     long long int w;
     Edge(int u,int v,long long int w)
     {
        this->u=u;
        this->v=v;
        this->w=w;
     }
};
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}
int dsu_find(int node)
{
    if (parent[node] == -1)
        return node;
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}
void union_size(int node1, int node2)
{
    int l1 = dsu_find(node1);
    int l2 = dsu_find(node2);
    if (group_size[l1] > group_size[l2])
    {
        parent[l2] = l1;
        group_size[l1] += group_size[l2];
    }
    else
    {
        parent[l1] = l2;
        group_size[l2] += group_size[l1];
    }
}
bool cmp(Edge a, Edge b)
{
     return a.w<b.w;
}
int main()
{
    int n,e;
    cin>>n>>e;
    init(n);
    vector<Edge> edgeList;
    while(e--)
    {
        int a,b;
        long long int c;
        cin>>a>>b>>c;
        edgeList.push_back(Edge(a,b,c));
    }
    long long int total=0;
    sort(edgeList.begin(),edgeList.end(),cmp);
    for(Edge edge: edgeList)
    {
        int leaderA=dsu_find(edge.u);
        int leaderB=dsu_find(edge.v);
        if(leaderA!=leaderB)
        {
               total+=edge.w;
               union_size(edge.u,edge.v);
        }
    }
    bool ans=true;
    for(int i=1;i<=n;i++)
    {
        int leader1=dsu_find(1);
        int leader2=dsu_find(i);
        if(leader1!=leader2)
        ans=false;
    }
    if(ans==false)cout<<"IMPOSSIBLE";
    else cout<<total<<endl;
    return 0;
}