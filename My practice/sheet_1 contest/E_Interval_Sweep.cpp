#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int sum=a+b;
    if(sum%2==0)
    {
        if(a==b)
        cout<<"YES";
        else
        cout<<"NO";
    }
    else
    {
        if(a+1==b || b+1==a)
        cout<<"YES";
        else
        cout<<"NO";
    }
    return 0;
}