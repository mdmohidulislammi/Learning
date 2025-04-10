#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
cin.tie(NULL);
    int test;
    cin>>test;
    priority_queue<int,vector<int> ,greater<int>> pq;
    while(test--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int val;
            cin>>val;
            pq.push(val);
        }
        else if(op==2)
        {
            if(pq.empty())
            cout<<"empty";
            else
            {
                cout<<pq.top();
                int occ=pq.top();
                pq.pop();
                while(!pq.empty())
                {
                    if(occ==pq.top())
                    pq.pop();
                    else break;
                }
            }
            cout<<"\n";
        }
    }
    return 0;
}