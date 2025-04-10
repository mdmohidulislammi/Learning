#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    map<char,int>mp;
    for(char c :s)
    {
        mp[c]++;
    }
    int ODD_count=0;
    for(pair<char,int> it: mp)
    {
        if(it.second%2 !=0 )
        ODD_count++;
    }
    if(ODD_count>1)
    {
        cout<<"NO SOLUTION";
        return 0;
    }
    string first,middle,last;
    int n=s.size();
    for(auto it: mp)
    {
        if(it.second%2 !=0)
        {
            for(int i=0;i<it.second;i++)
            middle.push_back(it.first);
        }
        else
        {
            for(int i=0;i<it.second/2;i++)
            {
                first.push_back(it.first);
                last.push_back(it.first);
            }
        }
    }
    reverse(last.begin(),last.end());
    cout<<first<<middle<<last;
    return 0;
}