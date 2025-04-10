#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, weight;
    cin >> n >> weight;
    int Weight_array[n], val_array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> Weight_array[i] >> val_array[i];
    }
    int knapsack[n + 1][weight + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= weight; j++)
        {
            if (i == 0 || j == 0)
                knapsack[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=weight;j++)
        {
            if(Weight_array[i-1]<=j)
            {
                int op1=knapsack[i-1][j-Weight_array[i-1]]+val_array[i-1];
                int op2=knapsack[i-1][j];
                knapsack[i][j]=max(op1,op2);
            }
            else
            { 
                knapsack[i][j]=knapsack[i-1][j];
            }
        }
    }
    cout<<knapsack[n][weight];
    return 0;
}