#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int parent[N];
int group_size[N];
//vector<int> graph[N];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=-1;
        group_size[i]=1;
    }
}
int find(int node)
{
    if(parent[node]==-1) return node;
    int leader=find(parent[node]);
    parent[node]=leader;
    return leader;
}
void union_size(int node1, int node2)
{
    int leaderA=find(node1);
    int leaderB=find(node2);
    if(leaderA==leaderB) return ;
    if(group_size[leaderA]<group_size[leaderB])
    {
        parent[leaderA]=leaderB;
        group_size[leaderB]+=group_size[leaderA];
    }
    else 
    {
        parent[leaderB]=leaderA;
        group_size[leaderA]+=group_size[leaderB];
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    init(n);
    int cycle=0;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        int leaderA=find(a);
        int leaderB=find(b);
        if(leaderA!=leaderB)
        union_size(a,b);
        else 
        cycle++;
    }
    cout<<cycle;
    return 0;
}