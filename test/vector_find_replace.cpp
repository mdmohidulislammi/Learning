#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for (int i = 0; i <n; i++)
    {
        int val;
        cin >> val;
        v.push_back(val);
    }
    int val, repl_val, value;
    int index;
    cin >> val >> repl_val;
    cin >> value;
    bool found=false;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 2)
            v[i] = repl_val;
        if (v[i] == value)
        {
            index = i;
            found=true;
        }
    }
    for (int val : v)
        cout << val << " ";
    if(found) cout<<endl<<index;
    else cout<<endl<<-1;
    return 0;
}