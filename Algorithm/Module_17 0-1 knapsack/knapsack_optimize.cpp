#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
const int MaxWeight=1000;
int dp[N][MaxWeight];
int knapsack(int n, int val[], int W[], int Weight)
{
    if (n < 0 || Weight == 0)
        return 0;
    if (dp[n][Weight] != -1)
        return dp[n][Weight];
    if (W[n] <= Weight)
    {
        // two option for traverse -->> 1.Gie dekha and 2. Na gie dekha
        int op1 = knapsack(n - 1, val, W, Weight - W[n]) + val[n];
        int op2 = knapsack(n - 1, val, W, Weight);
        return dp[n][Weight] = max(op1, op2);
    }
    else
    {
        // only one : na gie dekha lagbe ;
        return dp[n][Weight] = knapsack(n - 1, val, W, Weight);
    }
}
int main()
{
    int n, Weight;
    cin >> n >> Weight;
    int val[n], W[n];
    for (int i = 0; i < n; i++)
    {
        cin >> W[i] >> val[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= Weight; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knapsack(n - 1, val, W, Weight);
    return 0;
}