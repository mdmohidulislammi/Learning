#include<bits/stdc++.h>
using namespace std;
bool dp[10001][10001];
bool subset_sum(int n,int a[],int sum)
{
    if(n<0) 
    {
        if(sum==0) return true;
        else return false;
    }
    if(a[n]<=sum)
    {
        return dp[n][sum]=subset_sum(n-1,a,sum-a[n]) || subset_sum(n-1,a,sum);
    }
    else 
    return dp[n][sum]=subset_sum(n-1,a,sum);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int sum=0;
    for(int val: a)
    sum+=val;
    int target=sum/2;
    if(sum%2==1) cout<<"NO";
    else 
    {
        if(subset_sum(n-1,a,target))
        cout<<"YES";
        else cout<<"NO";
    }
    return 0;
}