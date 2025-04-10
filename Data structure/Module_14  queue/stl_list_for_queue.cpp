#include<bits/stdc++.h>
using namespace std;
class myQueue
{
    public:
    int sz=0;
        list<int>myList;
        void push(int value)
        {
            sz++;
            myList.push_back(value);
        }
        void pop()
        {
            sz--;
            myList.pop_front();
        }
        int front()
        {
           return myList.front();
        }
        int size()
        {
            return sz;
        }
        bool empty()
        {
            if(sz==0) return true;
            else return false;
        }
};
int main()
{
     myQueue qu;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        qu.push(value);
    }
    while(!qu.empty())
    {
        cout<<qu.front()<<endl;
        qu.pop();
    }
    return 0;
}