#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        set<int> s;
        int array_num;
        cin >> array_num;
        for (int j = 0; j < array_num; j++)
        {
            int value;
            cin >> value;
            s.insert(value);
        }

        for (auto it : s)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}