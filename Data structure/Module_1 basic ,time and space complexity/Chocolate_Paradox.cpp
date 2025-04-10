#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int d=c%a,e=c%b;
    if(c%a==0 || c%b==0 || d%b==0 || e%a==0)
    cout<<"YES";
    else
    cout<<"NO";
    return 0;
}