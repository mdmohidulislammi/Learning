#include<bits/stdc++.h>
using namespace std;
int main()
{
    string name , word;
    int cnt=0;
    getline(cin,name);
    cin>>word;
    string wor;
    stringstream ss(name);
    while(ss>>wor)
    {
        if(wor==word)
        cnt++;
    }
    cout<<cnt;
    return 0;
}