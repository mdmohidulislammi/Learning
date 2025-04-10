#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n;
    cin >> n;
   getchar();
    for (int i = 0; i < n; i++)
    {
        stack<char> st;
        string s;
        cin >> s;
        for (char c : s)
        {
            if (c == '1')
            {
                if (!st.empty() && st.top() == '0')
                    st.pop();
                else
                    st.push(c);
            }
            else if (c == '0')
            {
                if (!st.empty() && st.top() == '1')
                    st.pop();
                else
                    st.push(c);
            }
        }
        if (st.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}