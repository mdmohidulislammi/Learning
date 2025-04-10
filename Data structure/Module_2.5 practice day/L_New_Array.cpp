#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n),c(2*n);
    for(int i=0;i<a.size();i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    c=b;
    c.insert(c.begin()+n,a.begin(),a.end());
    for(int d:c)
    cout<<d<<" ";
    return 0;
}