#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b;
    int mx=max(a,b);
    for(int i=1;i<=mx;i++)
    {
      if(a%i==0 && b%i==0)
      c=i;
    }
    cout<<c;    
    return 0;
}