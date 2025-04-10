#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    for(int i=0;i<test;i++)
    {
        int n;
        cin>>n;
        char s[n];
        cin>>s;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(s[i+1]=='1')
                cnt++;
            }
            if(s[i]=='1')
            {
                if(s[i+1]=='0')
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}