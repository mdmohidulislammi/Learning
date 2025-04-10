#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    double fractional=(double)(a*b)/c;
    long long ld=(a*b)/c;
    if(fractional-ld==0)
    {
        if(ld<=2147483648 && ld>=-2147483648 )
        cout<<"int";
        else cout<<"long long";
    }
    else 
    cout<<"double";
    return 0;
}