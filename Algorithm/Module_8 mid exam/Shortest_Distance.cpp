#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e18;
int main()
{
    int n, e;
    cin >> n >> e;
    long long adj[101][101];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = N;
            if (i == j)
                adj[i][j] = 0;
        }
    }
    while (e--)
    {
        int a, b;
        long long int c;
        cin >> a >> b >> c;
        adj[a][b]=min(adj[a][b],c);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }
    int test;
    cin >> test;
    while (test--)
    {
        int src, des;
        cin >> src >> des;
        if (adj[src][des] == N)
            cout << -1 << endl;
        else
            cout << adj[src][des] << endl;
    }
    return 0;
}