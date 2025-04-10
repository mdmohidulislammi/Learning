#include<bits/stdc++.h>
using namespace std;
int dp[10000][10000];
int unbound(int n,int w[],int v[],int s)
{
    if(n< 0 || s==0) return 0;
    if(dp[n][s]!=-1) return dp[n][s];
    if(w[n]<= s)
    {
        int op1=unbound(n,w,v,s-w[n])+v[n];
        int op2=unbound(n-1,w,v,s);
        return dp[n][s]=max(op1,op2);
    }
    else 
    return dp[n][s]= unbound(n-1,w,v,s);
}
int main()
{
    int n,s;
    cin>>n>>s;
    int w[n],v[n];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    cin>>w[i];
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<unbound(n-1,w,v,s);
    return 0;
}