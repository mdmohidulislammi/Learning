#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        string s;
        cin>>s;
        while(s.find("101")!=-1)
        {cnt++;}
        if(cnt==0)
        cout<<"Bad";
        else
        cout<<"Good";
    }
    return 0;
}