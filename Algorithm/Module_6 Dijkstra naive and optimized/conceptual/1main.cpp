#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<pair<int,int>> weighted_graph[N];
int dis[N];
int par[N];
void dijkstra(int src)
{
   priority_queue<pair<int,int>,vector<pair<int, int>>, greater<pair<int,int>>>pq;
    pq.push({0,src});
    dis[src]=0;
    par[src]=0;
    while(!pq.empty())
    {
        pair<int,int>parent=pq.top();
        int parentNode=parent.second;
        int parentCost=parent.second;
        pq.pop();
        for(pair<int,int> child: weighted_graph[parentNode])
        {
            int childNode=child.second;
            int childCost=child.first;
            if(dis[parentNode]+childCost<dis[childNode])
            {
                dis[childNode]=dis[parentNode]+childCost;
                pq.push({dis[childNode],childNode});
                par[childNode]=parentNode;
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b,weight;
        cin>>a>>b>>weight;
        weighted_graph[a].push_back({weight,b});
        weighted_graph[b].push_back({weight,a});
    }
    for(int i=1;i<=n;i++)
    {
        dis[i]=INT_MAX;
    }
    int src=1;
    dijkstra(src);
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<i<<" -->>" <<dis[i]<<endl;
    // }
    int current=n;
    vector<int>v;
    while(1)
    {
        v.push_back(current);
        if(current==src)break;
        current=par[current];
    }
    reverse(v.begin(),v.end());
    for(int val: v)
    cout<<val<<" ";
    return 0;
}