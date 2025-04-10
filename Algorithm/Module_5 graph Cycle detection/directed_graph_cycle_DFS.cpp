#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> U_graph[N];
bool is_visit[N];
bool path_visit[N];
bool ans;
void DFS(int src)
{
    is_visit[src] = true;
    path_visit[src] = true;
    for (int child : U_graph[src])
    {
        if (path_visit[child])
            ans = true;
        if (!is_visit[child])
        {
            DFS(child);
        }
    }
    path_visit[src] = false;
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        U_graph[a].push_back(b);
    }
    memset(is_visit, false, sizeof(is_visit));
    memset(path_visit, false, sizeof(path_visit));
    ans = false;
    for (int i = 0; i < n; i++)
    {
        if (!is_visit[i])
            DFS(i);
    }
    if (ans)
        cout << "Cycle Detected";
    else
        cout << " Cycle Not Detected";
    return 0;
}