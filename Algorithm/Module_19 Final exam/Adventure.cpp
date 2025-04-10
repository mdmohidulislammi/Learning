#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int recursion(int n,int we[],int v[],int w)
{
    if(n<0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];
    if(we[n]<=w)
    {
        int op1=recursion(n-1,we,v,w-we[n])+v[n];
        int op2=recursion(n-1,we,v,w);
        return dp[n][w]=max(op1,op2);
    }
    else return dp[n][w]= recursion(n-1,we,v,w);
}
int main()
{
    int test;
    cin>>test;
    for(int p=0;p<test;p++)
    {
        int n,w;
        cin>>n>>w;
        int we[n],v[n];
        for(int i=0;i<n;i++)cin>>we[i];
        for(int i=0;i<n;i++) cin>>v[i];
        memset(dp,-1,sizeof(dp));
        cout<<recursion(n-1,we,v,w)<<endl;
    }
    return 0;
}