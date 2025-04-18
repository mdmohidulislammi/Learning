#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int parent[N];
int group_size[N];
class edge
{
    public:
          int u,v,w;
          edge(int u,int v,int w)
          {
            this->u=u;
            this->v=v;
            this->w=w;
          }
};
bool cmp(edge a, edge b)
{
     return a.w<b.w;
}
int initialization(int n)
{
    for(int i=0;i<n;i++)
    {
       parent[i]=-1;
       group_size[i]=1;
    }
}
int dsu_find(int node)
{
    if(parent[node]==-1) return node;
    int leader=dsu_find(parent[node]);
    parent[node]=leader;
    return leader;
}
void dsu_union_by_size(int node1, int node2)
{
    int leaderA=dsu_find(node1);
    int leaderB=dsu_find(node2);
    if(group_size[leaderA]>group_size[leaderB])
    {
        parent[leaderB]=leaderA;
        group_size[leaderA]+=group_size[leaderB];
    }
    else 
    {
        parent[leaderA]=leaderB;
        group_size[leaderB]+=group_size[leaderA];
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    initialization(n);
    vector<edge> edgeList;
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edgeList.push_back(edge(a,b,c));
    }
    sort(edgeList.begin(),edgeList.end(),cmp);
    int totalCost=0;
    for(edge ed: edgeList)
    {
        int leaderU=dsu_find(ed.u);
        int leaderV=dsu_find(ed.v);
        if(leaderU==leaderV)
        {
            continue;
        }
        else 
        {
            dsu_union_by_size(leaderU,leaderV);
            totalCost+=ed.w;
        }
    }
    cout<<totalCost<<endl;
    for(edge ed: edgeList)
    {cout<<ed.u<<" "<<ed.v<<" "<<ed.w<<endl;}
    return 0;
}