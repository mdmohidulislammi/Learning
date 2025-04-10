#include <bits/stdc++.h>
using namespace std;
vector<int> graph[10005];
bool ans[10005];
int level[10005];
vector<int>v;
void print_level_node(int L)
{
    queue<int> q;
    q.push(0);
    ans[0] = true;
    level[0] = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        if (level[parent] == L)
            v.push_back(parent);
        for (int child : graph[parent])
        {
            if (!ans[child])
            {
                q.push(child);
                ans[child] = true;
                level[child] = level[parent] + 1;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    v.clear();

    memset(ans, false, sizeof(ans));
    int L;
    cin >> L;
    print_level_node(L);
    sort(v.begin(),v.end(),greater<int>());
    for(int val: v)
    cout<<val<<" ";

    return 0;
}