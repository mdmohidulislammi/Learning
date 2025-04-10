#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int >mp;
    mp.insert({"Sakib al hassan", 10});
    mp.insert({"mohidul", 100});
   mp["Sakib al has"]=11;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<" " <<it->second<<endl;
    }
    return 0;
}