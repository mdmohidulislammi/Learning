#include<bits/stdc++.h>
using namespace std;
long long int dp[10001][10001];
long long int rec(int n,int a[],long long sum)
{
    if (n < 0)
    {
        if (sum == 0)
            return 1;
        else
            return 0;
    }
    if(dp[n][sum]!=-1)
    return dp[n][sum];
    if (a[n] <= sum)
    {
        int op1 = rec(n - 1, a, sum - a[n]);
        int op2 = rec(n - 1, a, sum);
        return dp[n][sum]=op1 + op2;
    }
    else
        return dp[n][sum]=rec(n - 1, a, sum);
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int a[n];
        long long ans=0;
        for(int i=0;i<n-2;i++)
        {
            cin>>a[i];
            ans+=a[i];
        }
        memset(dp,-1,sizeof(dp));
        long long sum;
        cin>>sum;
        int b[n];
        for(int i=0;i<=n;i++)
        b[i]=i;
        cout<<rec(n,b,sum-ans)<<endl;
    }
    return 0;
}