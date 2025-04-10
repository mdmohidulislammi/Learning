#include<bits/stdc++.h>
using namespace std;
int n,e;
vector<int>graph[10005];
bool is_visit[10005];
void DFS_components(int s)
{
    cout<<s<<endl;
    is_visit[s]=true;
    for(int i=0;i<graph[s].size();i++)
    {
        if(!is_visit[graph[s][i]])
            DFS_components(graph[s][i]);
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
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(is_visit,false,sizeof(is_visit));   
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(!is_visit[i])
        {
           DFS_components(i);
           cnt++;
        }
    }
    cout<<cnt;
    return 0;
}