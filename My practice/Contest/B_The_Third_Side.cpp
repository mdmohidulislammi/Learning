#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        int n;
        cin >> n;
        vector<int>a;
        for (int i = 0; i < n; i++)
            {
                int val;
                cin>>val;
                a.push_back(val);
            }
        if (n == 1)
            cout << a[0];
        else
        {
          while(n>1)
          {
            int sum=a[a.size()-1]+a[a.size()-2];
            a.pop_back();
            a.pop_back();
            a.push_back(sum-1);
            n--;
          }
          cout<<a[0];
        }

            cout << endl;
    }
    return 0;
}