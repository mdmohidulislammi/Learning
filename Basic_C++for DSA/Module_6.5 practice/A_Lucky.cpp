#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
       string s;
       cin>>s;
       if(int(s[0]-'0')+int(s[1]-'0')+int (s[2]-'0')==int(s[3]-'0')+int(s[4]-'0')+int (s[5]-'0'))       
       {
        cout<<"YES"<<endl;
       }
       else
       {
        cout<<"NO"<<endl;
       }
    }
    return 0;
}