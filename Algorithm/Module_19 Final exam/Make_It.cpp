#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int val;
bool rec(int n)
{
    if(n>val) return false;
    else if(n==val) return true;
    if(dp[n]!=-1) return dp[n];
    return dp[n]= rec(n*2) || rec(n+3);
}
int main()
{
    int test;
    cin>>test;
    for(int i=0;i<test;i++)
    {
        cin>>val;
        memset(dp,-1,sizeof(dp));
        if(rec(1)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}