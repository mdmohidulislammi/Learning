#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    for(int i=0;i<test;i++)
    {
        int n,sum=0;
        cin>>n;
        int cnt[26]={0};
        char s[n];
            cin>>s;
        for(int j=0;j<n;j++)
        {
            cnt[s[j]-'A']++;                         
        }
        for(int j=0;j<26;j++)
        {
            if(cnt[j]>1)
            sum=sum+cnt[j]+1;
            else if(cnt[j]==1)
            sum=sum+2;
        }
        cout<<sum<< endl;
    }
    return 0;
}