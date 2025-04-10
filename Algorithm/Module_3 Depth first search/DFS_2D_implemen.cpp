#include<bits/stdc++.h>
using namespace std;
char ch[20][20];
int n,m;
vector<pair<int,int>>p={{0,1},{0,-1},{1,0},{-1,0}};
bool is_visit[20][20];
bool valid(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
    return false;
    return true;
}
void DFS_implementation(int si,int sj)
{
    cout<<si<<" "<<sj<<endl;
    is_visit[si][sj]=true;
    for(int i=0;i<4;i++)
    {
         int ci=si+p[i].first;
         int cj=sj+p[i].second;
         if(valid(ci,cj) && !is_visit[ci][cj])
         {
            DFS_implementation(ci,cj);
         }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>ch[i][j];
    }
    int sj,si;
    cin>>si>>sj;
    memset(is_visit,false,sizeof(is_visit));
    DFS_implementation(si,sj);
    return 0;
}