#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int cnt[26]={0};
    for(char c:s)
    {
        cnt[c-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<cnt[i];j++)
        cout<<char(i+'a')<<" ";
    }
    return 0;
}