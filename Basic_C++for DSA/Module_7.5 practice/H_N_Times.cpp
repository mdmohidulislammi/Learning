#include<bits/stdc++.h>
using namespace std;
void fun(int t)
{
    for(int i=0;i<t;i++)
    {
        int n;
        char c;
        cin>>n>>c;
        for(int j=0;j<n;j++)
        {cout<<c<<" ";}
        cout<<endl;
    }
}
int main()
{
    int t;
    cin>>t;
    fun(t);
    return 0;
}