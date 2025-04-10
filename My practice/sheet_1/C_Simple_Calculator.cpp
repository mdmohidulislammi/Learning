#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    long long sum=a+b;
    int difference=a-b;
    long long mul=a*b;
    cout<<a<<" + "<<b<<" = "<<sum<<endl<<a<<" * "<<b<<" = "<<mul<<endl<<a<<" - "<<b<<" = "<<difference;
    return 0;
}