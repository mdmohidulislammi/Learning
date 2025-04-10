#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int>pq;//small priority_queue<int,vector<int>,greater<int>)pq;
    while(true)
    {
        int command;
        cin>>command;
        if(command==0)
        {
            int value;
            cin>>value;
            pq.push(value);
        }
        else if(command==1)
        pq.pop();
        else if(command==2)
        cout<<pq.top()<<endl;
        else break;
    }
    return 0;
}