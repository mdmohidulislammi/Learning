#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int least_common_string(string a,int n, string b, int m)
{
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(a[n-1]==b[m-1])
    {
        return dp[n][m]= least_common_string(a,n-1,b,m-1)+1;
    }
    else
    {
        int first=least_common_string(a,n-1,b,m);
        int second=least_common_string(a,n,b,m-1);
        return dp[n][m]=max(first,second);
    }
}
int main()
{
    string a,b;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    cout<<least_common_string(a,a.size(),b,b.size());
    return 0;
}