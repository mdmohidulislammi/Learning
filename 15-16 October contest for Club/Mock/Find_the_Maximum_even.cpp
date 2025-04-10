#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mx = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
          int ans = a[i] + a[j];
            if (ans % 2 == 0)
            {
                mx=max(mx,ans);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]%2 ==0)
        mx=max(mx,a[i]);
    }
    cout << mx<<endl;
    return 0;
}