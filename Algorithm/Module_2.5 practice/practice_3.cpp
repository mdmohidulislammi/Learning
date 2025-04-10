#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, e;
        cin >> n >> e;
        vector<int> v[n];
        while (e--)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        int val;
        cin >> val;
        int child = 0;
        for (int value : v[val])
            child++;
        cout << child << endl;
    }
    return 0;
}