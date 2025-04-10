#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,word;
    int p=0;
    getline(cin,s);
    stringstream ss(s);
    while(ss>>word)
    {
        if(word=="Jessica")
        p=1;
    }
    if(p==1)
    cout<<"YES";
    else
    {
        cout<<"NO";
    }
    return 0;
}