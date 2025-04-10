#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int top_down(int n, int a[], int sum)
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
        int op1 = top_down(n - 1, a, sum - a[n]);
        int op2 = top_down(n - 1, a, sum);
        return dp[n][sum]=op1 || op2;
    }
    else
        return dp[n][sum]=top_down(n - 1, a, sum);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum;
    cin >> sum;
    memset(dp,-1,sizeof(dp));
    int ans = top_down(n - 1, a, sum);
    if (dp[n-1][sum])
        cout << "YES";
    else
        cout << "NO";
    return 0;
}