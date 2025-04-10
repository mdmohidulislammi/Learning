#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int cnt=0;
    bool inside_char=true;
    for(char c:s)
    {
        if(isalpha(c))
        {
            if (inside_char ==true) 
            {
                cnt++;
            }
            inside_char=false;
        }
        else
        {
            inside_char=true;
        }
    }

    cout<<cnt;
    return 0;
}
