#include <bits/stdc++.h>
using namespace std;
int parent[1001];
int gro[1001];
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        gro[i] = 1;
    }
}
int dsu_find(int node)
{
    if (parent[node] == -1)
        return node;
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}
void union_by_size(int n1, int n2)
{
    int l = dsu_find(n1);
    int L = dsu_find(n2);
    if (gro[l] < gro[L])
    {
        parent[l] = L;
        gro[L] += gro[l];
    }
    else
    {
        parent[L] = l;
        gro[l] += gro[L];
    }
}
int main()
{
    int n;
    cin >> n;
    init(n);
    vector<pair<int, int>> close, create;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        int leader1 = dsu_find(a);
        int leader2 = dsu_find(b);
        if (leader1 == leader2)
        {
            close.push_back({a, b});
        }
        else
        {
            union_by_size(a, b);
        }
    }
    for (int i = 2; i <= n; i++)
    {
        int lead = dsu_find(1);
        int leader = dsu_find(i);
        if (lead != leader)
            create.push_back({1, i});
    }
    cout << close.size() << endl;
    if (!close.empty())
    {
        for (int i = 0; i < close.size(); i++)
        {
            cout << close[i].first << " " << close[i].second << " " << create[i].first << " " << create[i].second << endl;
        }
    }
    return 0;
}