#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[100005];
    while(cin.getline(s,sizeof(s)))
    {
         int n=strlen(s),cnt[26]={0};
         for(int i=0;i<n;i++)
         {
            cnt[s[i]-'a']++;
         }
         for(int i=0;i<26;i++)
         {
             while(cnt[i]!=0)
             {
                cout<<(char)(i+'a');
                cnt[i]--;
             }
         }
         cout<<endl;
    }
    return 0;
}