#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    vector<char>v;
    while(cin>>c)
    {
         v.push_back(c);
    }
    int cnt[26]={0};
    for(int i=0;i<v.size();i++)
    {
        int val=(int)v[i]-'a';
        cnt[val]++;
    }  
    for(int i=0;i<26;i++)
    {
        if(cnt[i]!=0)
        cout<<(char)(i+'a')<<" : "<<cnt[i]<<endl;
    }
    return 0;
}