#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int>st,s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        st.push(value);
    }
    s=st;
    stack<int>stk;
    while(!s.empty())
    {
        stk.push(s.top());
        s.pop();
    }
    for(int i=0;i<n;i++)
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}