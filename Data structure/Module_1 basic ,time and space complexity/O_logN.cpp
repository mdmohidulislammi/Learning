#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int s=n;
    while(n>0)
    {
        cout<<n%10<<endl;
        n/=10;
    }
    for(int i=1;i<s;i*=2)
    {
        cout<<i<<endl;
    }
    return 0;
}