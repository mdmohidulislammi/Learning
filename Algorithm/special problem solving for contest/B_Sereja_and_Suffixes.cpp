#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=1;i<=n;i++)
    cin>>a[i];
    set<int>s;
    int b[m];
    for(int i=n;i>0;i--)
    {
        s.insert(a[i]);
        b[i]=s.size();
    }
    for(int i=0;i<m;i++)
    {
        int pos;
        cin>>pos;
        cout<<b[pos]<<endl;
    }
    // for(int i=1;i<=m;i++)
    // {
    //     int pos;
    //     cin>>pos;
    //     set<int> st;
    //     for(int j=pos-1;j<n;j++)
    //     {
    //        st.insert(a[j]);
    //     }
    //     cout<<st.size()<<endl;
    // }
    return 0;
}