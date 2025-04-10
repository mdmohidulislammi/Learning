#include<bits/stdc++.h>
using namespace std;
class myStack
{
    public:
    list<int> mylist;
    void push(int value)
    {
        mylist.push_back(value);
    }
    void pop()
    {
        mylist.pop_back();
    }
    int top()
    {
        return mylist.back();
    }
    int size()
    {
        return mylist.size();
    }
    bool empty()
    {
        if(mylist.size()==0)return true;
        else return false;
    }
};
int main()
{
    myStack st;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        st.push(val);
    }
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}