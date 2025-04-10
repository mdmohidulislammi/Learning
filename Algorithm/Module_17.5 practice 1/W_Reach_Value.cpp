#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll val;
bool knapsack(ll n)
{
    if(n>val) return false;
    if(n==val) return true;
    return knapsack(n*10) || knapsack(n*20);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
       
        cin>>val;
        if(knapsack(1)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}