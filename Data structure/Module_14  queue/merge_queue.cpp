#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int>q1,q2,merge_queue;
    int t1,t2;
    cin>>t1;
    for(int i=0;i<t1;i++)
    {
        int value;
        cin>>value;
        q1.push(value);
    }
    cin>>t2;
    for(int i=0;i<t2;i++)
    {
        int value;
        cin>>value;
        q2.push(value);
    }
    while(!q1.empty())
    {
        merge_queue.push(q1.front());
        q1.pop();
    }
    while(!q2.empty())
    {
        merge_queue.push(q2.front());
        q2.pop();
    }
    while(!merge_queue.empty())
    {
        cout<<merge_queue.front()<<" ";
        merge_queue.pop();
    }
    return 0;
}