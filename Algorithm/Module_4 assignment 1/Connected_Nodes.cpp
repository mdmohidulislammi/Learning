#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> graph_un[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph_un[a].push_back(b);
        graph_un[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        vector<int> v;
        int node;
        cin >> node;
        for (int val : graph_un[node])
            v.push_back(val);
        if (!v.empty())
        {
            sort(v.begin(), v.end(), greater<int>());
            for (int val : v)
                cout << val << " ";
            cout << endl;
        }
        else
            cout << "-1" << endl;
    }
    return 0;
}