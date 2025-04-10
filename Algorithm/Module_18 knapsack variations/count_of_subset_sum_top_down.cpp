#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int subset_sum_count(int n, int a[], int sum)
{
    if (n < 0)
    {
        if (sum == 0)
            return 1;
        else
            return 0;
    }
    if (a[n] <= sum)
    {
        int op1 = subset_sum_count(n - 1, a, sum - a[n]);
        int op2 = subset_sum_count(n - 1, a, sum);
        return dp[n][sum] = op1 + op2;
    }
    else
        return dp[n][sum] = subset_sum_count(n - 1, a, sum);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
        int sum;
        cin>>sum;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sum; j++)
            dp[i][j] = -1;
    }
    cout<<subset_sum_count(n-1,a,sum);
    return 0;
}