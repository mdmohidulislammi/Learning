#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
bool rec(int n,int a[],int sum)
{
    if(n<0)
    {
        if(sum==0) return true;
        else return false;
    }
    if(dp[n][sum]!=-1) return dp[n][sum];
    if(a[n]<=sum)
    return dp[n][sum]=rec(n-1,a,sum-a[n]) || rec(n-1,a,sum);
    else return dp[n][sum]=rec(n-1,a,sum);

}
int main()
{
    int test;
    cin>>test;
    for(int i=0;i<test;i++)
    {
        int n,marks;
        cin>>n>>marks;
        int a[n];
        for(int j=0;j<n;j++)
        cin>>a[j];
        memset(dp,-1,sizeof(dp));
        if(rec(n-1,a,1000-marks))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}