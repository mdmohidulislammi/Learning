#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    long long int d;
    char c,e;
    cin >> a >> c >> b >> e >> d;
    if(c=='+')
    {
        if(d==a+b)
        {
            cout<<"Yes";
        }
        else
        cout<<a+b;
    }
    else if(c=='*')
    {
        if(d==a*b)
        cout<<"Yes";
        else
        cout<<a*b;
    }
    else
    {
        if(d==a-b)
        {
            cout<<"Yes";
        }
        else
        cout<<a-b;
    }
    return 0;
}