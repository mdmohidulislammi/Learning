#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    ll adj[n][n];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = INT_MAX;
            if (i == j)
                adj[i][j] = 0;
        }
    }
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
           for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    int test;
    cin>>test;
    while(test--)
    {
        int s,d;
        cin>>s>>d;
        if(adj[s][d]<INT_MAX)cout<<adj[s][d]<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}