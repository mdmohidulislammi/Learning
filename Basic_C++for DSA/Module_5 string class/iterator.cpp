#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    //cout<<*s.begin()<<endl;
    //cout<<*(s.end()-1)<<endl;
    for(auto it=s.begin();it<s.end();it++)//for(string:: iterator it=s.begin())
    {
        cout<<*it<<endl;
    }    
    return 0;
}