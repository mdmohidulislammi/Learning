#include<bits/stdc++.h>
using namespace std;
void fun(int x,int n)
{
  long long int sum=0;
    for(int i=2;i<=n;i=i+2)
    {
        // for(int j=i+2;j<=i+2;j=j+2)
        // {
        //     p=p*x;
        //     cout<<p<<endl;
        // }
       sum=sum+pow(x,i);
    }
    cout<<sum;
}
int main()
{
    int n,x;
    cin>>x>>n;
    fun(x,n);
    return 0;
}