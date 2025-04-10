#include <bits/stdc++.h>
using namespace std;
int dp[1001][2001];
bool rec(int n, int a[], int sum)
{
    if (n < 0)
    {
        if (sum == 0)
            return true;
        else
            return false;
    }
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (a[n] <= sum)
    {
        return dp[n][sum] = rec(n - 1, a, sum - a[n]) || rec(n - 1, a, sum);
    }
    else
        return dp[n][sum] = rec(n - 1, a, sum);
}
int main()
{
    int test;
    cin >> test;
    for (int p = 0; p < test; p++)
    {
        memset(dp, -1, sizeof(dp));
        int n;
        cin >> n;
        int a[n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % 2 == 1)
            cout << "NO" << endl;
        else
        {
            if (rec(n - 1, a, sum / 2))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}