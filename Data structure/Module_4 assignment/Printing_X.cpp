#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
              if(i==j)
              {
                if(i==n/2)
                cout<<"X";
                else
                cout<<"\\";
              }
             else if(i+j==n-1)
             cout<<"/";
             else
             cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}