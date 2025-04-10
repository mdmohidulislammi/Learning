#include <bits/stdc++.h>
using namespace std;
long long int dp[10001];
long long int knapsack(long long int a[], int n)
{
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    long long int op1 = a[n] + knapsack(a, n - 2);
    long long int op2 = knapsack(a, n - 1);
    return dp[n] = max(op1, op2);
}

int main()
{
    int test;
    cin >> test;
    for (int p = 1; p <= test; p++)
    {
        int n;
        cin >> n;
        long long int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            dp[i] = -1;
        cout << "Case " << p << ": " << knapsack(a, n - 1) << endl;
    }
    return 0;
}