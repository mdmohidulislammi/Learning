#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    for(int i=0;i<test;i++)
    {
        int  n,k;
        cin>>n>>k;
        if(n%2 ==0)
        {
            int p=k/2;
            if(p%2 ==0)
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
        else if(n%2 !=0)
        {
            int p=ceil(1.0*k/2);
            if(p%2 ==0)
            {
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}