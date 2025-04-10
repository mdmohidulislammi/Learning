#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    bool found=false;
    for(int i=a;i<=b;i++)
    {
       int luck=i;
       while(luck>=10)
       {
         luck/=10;
       }
       if(luck==4 || luck==7)
       {
        found=true;
        cout<<i<<" ";
       }
    }
    if(!found) cout<<-1;
    return 0;
}