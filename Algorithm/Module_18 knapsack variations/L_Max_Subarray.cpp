#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    for(int i=0;i<test;i++)
    {
        int n;
        cin>>n;
        int a[n];
        for(int j=0;j<n;j++)
        cin>>a[j];
        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                for(int p=k+1;k<n;k++)
                cout<<j<<" "<<k<<" "<<p<<" ";
            }cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}