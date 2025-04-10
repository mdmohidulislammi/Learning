#include<bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll> 
using namespace std;
const int N=1e5;
int parent[N];
ll dis[N];
vector<pi> graph[N];
class cmp
{ public:
    bool operator()(pi a, pi b)
    {
        return a.second> b.second;
    }
};
void bfs(int src ,int cost)
{
    priority_queue<pi,vector<pi> , cmp> pq;
    pq.push({src,cost});
    dis[src]=0;
    //parent[src]=1;
    while(!pq.empty())
    {
        pi par=pq.top();
        pq.pop();
        for(pi child: graph[par.first]){
        if(child.second+ par.second< dis[child.first])
        {
            dis[child.first]=child.second+par.second;
            parent[child.first]=par.first;
            pq.push({child.first,dis[child.first]});
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
        int a,b;
        ll c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    for(int i=1;i<=n;i++)
    {
         parent[i]=-1;
         dis[i]=1e18;
    }
    bfs(1,0);
    int st=n;
    vector<int> path;
    while(st!=-1)
    {
        path.push_back(st);
        st=parent[st];
    }
    reverse(path.begin(),path.end());
    for(int v: path)
    cout<<v<<" ";
    return 0;
}