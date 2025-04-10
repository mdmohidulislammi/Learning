#include<bits/stdc++.h>
using namespace std;
int parent[1000000];
int group_size[1000000];
void initialization(int n)
{
    for(int i=1;i<=n;i++)
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
void dsu_union_size(int node1, int node2)
{
    int leaderA=dsu_find(node1);
    int leaderB=dsu_find(node2);
    if(leaderA==leaderB) return ;
    if(group_size[leaderA]> group_size[leaderB])
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
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        dsu_union_size(a,b);
    }
    vector<int> leaders;
    for(int i=1;i<=n;i++)
    {
        if(parent[i]==-1)
        leaders.push_back(i);
    }
    cout<<leaders.size()-1<<endl;
    for(int i=1;i<leaders.size();i++)
    {
        cout<<leaders[i-1]<<" "<<leaders[i]<<endl;
    }
    return 0;
}