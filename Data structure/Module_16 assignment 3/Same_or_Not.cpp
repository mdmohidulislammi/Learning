#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int>st;
    queue<int>q;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        st.push(value);
    }
    for(int i=0;i<m;i++)
    {
        int value;
        cin>>value;
        q.push(value);
    }
    bool flag=true;
    if(m==n)
    {
        while(!st.empty() && !q.empty())
        {
            if(st.top()!=q.front())
            {
              flag=  false;
                break;
            }
            st.pop();
            q.pop();
        }
    }
    if(m!=n) cout<<"NO";
    else if(flag==false) cout<<"NO";
    else cout<<"YES";
    return 0;
}