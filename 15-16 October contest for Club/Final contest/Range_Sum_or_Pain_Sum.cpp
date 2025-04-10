#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n / 2; i++)
    {
        a[i] = i + 1;
    }
    int j = 1;
    for (int i = (n / 2); i <= n; i++)
    {
        a[i] = j;
        j++;
    }
    sort(a, a + n);
    int pre_sum[n];
    pre_sum[0] = 0;
    pre_sum[1] = a[0];
    for (int i = 2; i <= n; i++)
    {
        pre_sum[i] = pre_sum[i - 1] + a[i - 1];
    }
    for (int p = 0; p < q; p++)
    {
        int l, r;
        cin >> l >> r;
            cout << pre_sum[r] - pre_sum[l-1];
        cout << endl;
    }
    return 0;
}