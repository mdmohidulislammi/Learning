#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long int b[n];
    b[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        b[i] = b[i - 1] + a[i];
    }
    for (int i = 0; i < q; i++)
    {
        int s, d;
        cin >> s >> d;
        cout << b[d] - b[s - 1] << endl;
    }
    return 0;
}