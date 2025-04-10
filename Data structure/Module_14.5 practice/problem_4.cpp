#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int>q;
    stack<int>st;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        q.push(value);
    }
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }                                    
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    // while(!q.empty())
    // {
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
    return 0;
}