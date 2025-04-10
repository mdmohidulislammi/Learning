#include<bits/stdc++.h>
using namespace std;
class edge
{
    public: 
    int u, v, w;
    edge( int u, int v, int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
void convert(int n, vector<edge> edgeList)
{
    int mat[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mat[i][j]=-1;
            if(i==j) mat[i][j]=0;
        }
    }
    for(edge ed: edgeList)
    {
        mat[ed.u][ed.v]=ed.w;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<edge> edgeList;
    while(e--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        edgeList.push_back(edge(a,b,c));
        edgeList.push_back(edge(b,a,c));
    }    
    convert(n,edgeList);
    return 0;
}