#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int>st;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        st.push(value);
    }
    int pos;
    cin>>pos;
    for(int i=0;i<=n-pos;i++)
    {
        if(i==(n-pos))
        cout<<st.top();
        st.pop();
    }
    return 0;
}