#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cnt[26]={0};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        cnt[c-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        while(cnt[i]!=0)
        {
            cout<<(char)(i+'a');
        cnt[i]--;
        }
    }
    return  0;
}
