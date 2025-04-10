#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tst;
    cin>>tst;
    for(int m=0;m<tst;m++)
    {
        int n,s,q=0;
        cin>>n>>s;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        } 
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int p=j+1;p<n;p++)
                {
                    if(a[i]+a[j]+a[p]-s ==0)
                    {
                        q=1;
                    }
                }
            }
        }
        if(q==1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}