#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    for(int p=0;p<test;p++)
    {
        int n,even=0,odd=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]%2==0)
            even++;

            else
            odd++;
        } 
        if(n%2==0)
        {
            if(odd>=n/2)
            {
                int s=odd-n/2;
                cout<<s<<endl;
            }
            else if(even>=n/2)
            {
               int s=even-n/2;
               cout<<s<<endl;
            }
        } 
        else
        cout<<"-1"<<endl;      
    }
    return 0;
}