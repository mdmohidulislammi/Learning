#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        int current = v.size() - 1;
        while (current != 0)
        {
            int parent = (current - 1) / 2;
            if (v[parent] > v[current])
                swap(v[parent], v[current]);
            else
                break;
            current = parent;
        }
    }
    for (int val : v)
    {
        cout << val << " ";
    }
    return 0;
}