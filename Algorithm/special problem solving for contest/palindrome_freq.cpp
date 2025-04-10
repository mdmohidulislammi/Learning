#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int a[26]={0};
    for(char c: s)
    {
        a[c-'A']++;
    }
    int cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(a[i]%2!=0)
        cnt++;
    }
    if(cnt>1)
    {
        cout<<"NO SOLUTION";
        return 0;
    }
    string first,middle,last;
    for(int i=0;i<s.size();i++)
    {
        if(a[i]%2 !=0)
        {
            for(int j=1;j<=a[i];j++)
            middle.push_back(char(i+'A'));
        }
        else
        {
            for(int j=1;j<=a[i]/2;j++)
            {
                first.push_back(char(i+'A'));
                last.push_back(char(i+'A'));
            }
        }
    }
    reverse(last.begin(),last.end());
    cout<<first<<middle<<last;
    return 0;
}