#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>0;j/=10)
        {
            cout<<j%10<<" ";
        }
        cout<<endl;
    }
    return 0;
}