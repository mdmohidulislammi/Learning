#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int ans = 0;
    int crr = INT_MAX;
    // sort(v.begin(),v.end(),greater<int>());
    sort(v.begin(), v.end(), greater<int>());
    for (int val : v)
    {
        if (crr > 0)
        {
            crr = min(crr-1, val);
            ans += crr;
        }
    }
    cout << ans;
}