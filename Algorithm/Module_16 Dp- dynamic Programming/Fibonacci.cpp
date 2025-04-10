#include <bits/stdc++.h>
//#define ll long long int
#define ul unsigned long long
using namespace std;
const int N = 1e5 + 5;
ul dp[N];
ul fibo(ul n)
{
    if (n == 0 || n == 1)
        return n;
    if (dp[n] != -1)//memoization
        return dp[n];//memoization
    ul ans = fibo(n - 1) + fibo(n - 2);
    dp[n] = ans;//memoization
    return ans;
}
int main()
{
    ul n;
    cin >> n;
    memset(dp,-1, sizeof(dp));
    cout << fibo(n) << endl;
    return 0;
}