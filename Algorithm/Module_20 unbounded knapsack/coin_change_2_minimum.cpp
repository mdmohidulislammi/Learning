#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int w[n];
    for (int i = 0; i < n; i++)
        cin >> w[i];
    int sum;
    cin >> sum;
    int dp[n + 1][sum + 1];
    dp[0][0] = 0;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = INT_MAX -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; i++)
        {
            if (w[i - 1] <= j)
                dp[i][j] = min(1 + dp[i][j - w[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][sum] << endl;
    return 0;
}