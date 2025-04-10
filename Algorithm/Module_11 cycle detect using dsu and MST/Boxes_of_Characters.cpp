#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        string s;
        cin >> s;
        int con = 0;
        int vow = 0;
        int di = 0;
        for (char c : s)
        {
            if (c == 'a' || c == 'i' || c == 'o' || c == 'u' || c == 'e')
                vow++;
            else if (c - '0' >= 0 && c - '0' < 10)
                di++;
            else
                con++;
        }
        float c = (con*1.0)/3*1.0;
        float v = (vow*1.0) /2*1.0;
        int vo=v/1;
        int co=c/1;
        if (c >= v && c >= di)
        {
            if (c!=co)
                co++;
            cout << c << endl;
        }
        else if (v >= c && v >= di)
        {
            if (v!=vo)
                vo++;
                cout<<vo<<endl;
        }
        else if (di >= c && di >= v)
            cout << di << endl;
    }
    return 0;
}