#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    queue<string> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int cmd;
        string s;
        cin >> cmd;
        if (cmd == 0)
            cin >> s;
        if (cmd == 1 && q.empty())
            cout << "Invalid" << endl;
        else if (cmd == 1 && !q.empty())
            {
                cout<<q.front()<<endl;
                q.pop();
            }
        else if (cmd == 0)
            q.push(s);
    }
    return 0;
}