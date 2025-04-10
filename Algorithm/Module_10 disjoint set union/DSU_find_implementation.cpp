#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int group_size[N];
int group_level[N];
void par(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
        group_level[i] = 0;
    }
}
int find(int node)
{
    if (parent[node] == -1)
        return node;
    // optimized
    int leader = find(parent[node]);
    parent[node] = leader;
    return leader;
    // first implement
    //  return node;
    //  return DSU(parent[node]);
}
void dsu_union_by_rank(int node1, int node2)
{
    int leaderA = find(node1);
    int leaderB = find(node2);
    if (group_level[leaderA] > group_level[leaderB])
    {
        parent[leaderB] = leaderA;
    }
    else if (group_level[leaderB] > group_level[leaderA])
    {
        parent[leaderA] = leaderB;
    }
    else
    {
        parent[leaderA] = leaderB;
        group_level[leaderB]++;
    }
}
void DSU_union(int node1, int node2)
{
    int leaderA = find(node1);
    int leaderB = find(node2);
    if (group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
int main()
{
    par(7);
    dsu_union_by_rank(1, 2);
    dsu_union_by_rank(2, 3);
    dsu_union_by_rank(3, 4);
    dsu_union_by_rank(5, 6);
    dsu_union_by_rank(6, 7);
    dsu_union_by_rank(6, 1);
    for (int i = 1; i <= 7; i++)
    {
        cout << "Parent-> " << parent[i] <<endl;// << "Leader->>" << find(i) << endl;
    }
    // first
    //  par(4);
    //  cout << find(0) << endl;
    //  cout << find(1) << endl;
    //  cout << find(2) << endl;
    //  cout << find(3) << endl;
    return 0;
}