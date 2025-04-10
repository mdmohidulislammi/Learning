#include<bits/stdc++.h>
using namespace std;
int fact(int n)// O(N)
{
    if(n==0) return 1;
    int fa=n*(fact(n-1));
    return fa;
}
int main()
{
    int n;
    cin>>n;
    cout<<fact(n)<<endl;
    // int ans=1;
    // for(int i=1;i<=n;i++)  // O(N)
    // {
    //     ans*=i;
    // }
    // cout<<ans;
    return 0;
}