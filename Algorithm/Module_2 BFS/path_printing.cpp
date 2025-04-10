#include<bits/stdc++.h>
using namespace std;
vector<int>node[1005];
bool duplicate_check[1005];
int parent[1005];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    duplicate_check[src]=true;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();

        for(int child: node[p])
        {
            if(!duplicate_check[child])
            {
                q.push(child);
                duplicate_check[child]=true;
                parent[child]=p;
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
        cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    int src,des;
    cin>>src>>des;
    memset(duplicate_check,false,sizeof(duplicate_check));
    memset(parent,-1,sizeof(parent));
    bfs(src);
    vector<int>path;
    int x=des;
    while(x!=-1)
    {
        path.push_back(x);
        x=parent[x];
    }
    reverse(path.begin(),path.end());
    for(int val: path)
    cout<<val<<" ";
    cout<<endl;
    return 0;
}