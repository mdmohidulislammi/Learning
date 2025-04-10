#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int knapsack(int n,int w[],int v[] ,int sum)
{
    if(n==0 || sum==0) return 0;
    if(dp[n][sum]!=-1) return dp[n][sum];
    if(w[n-1]<=sum)
    return dp[n][sum] =max(knapsack(n,w,v,sum-w[n-1])+v[n-1],knapsack(n-1,w,v,sum));
    else return dp[n][sum]=knapsack(n-1,w,v,sum);
}
int main()
{
    int n;
    cin>>n;
    int w[n],v[n];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        w[i]=i+1;
    }
    cout<<knapsack(n,w,v,n);
    return 0;
}