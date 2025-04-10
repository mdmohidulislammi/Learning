#include<iostream>
using namespace std;
int main()
{
    int a;
    char c;
    long long int b;
    
    cin>>a>>b>>c;
    long long int d=int(a);//long long int d=(long long int)(a);
    cout<<a<<endl<<b<<endl<<c<<endl<<int (c)<<endl<<d;
    return 0;
}