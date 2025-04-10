#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    char c=s[0];
    s[0]=c+32;
    reverse(s.begin(),s.end());
    cout<<s;
    return 0;
}