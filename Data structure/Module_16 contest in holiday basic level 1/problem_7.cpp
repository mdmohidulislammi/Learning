#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int>q;
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int value;
        cin>>value;
        q.push(value);
    }
    int pos;
    cin>>pos;
    for(int i=0;i<t;i++)
    {
        if(i==pos-1)
        q.pop();
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}