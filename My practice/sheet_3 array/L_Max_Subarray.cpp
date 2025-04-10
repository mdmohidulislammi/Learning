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
        {
            cin>>a[j];
        }
        for(int p=0;p<n-1;p++)
        {
            for(int j=p;j<n;j++)
            {
                cout<<max(a[i],a[j])<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}