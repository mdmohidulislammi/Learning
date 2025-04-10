#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
    int value;
    Node* next;
    Node * prev;
    Node(int value)
    {
        this->value=value;
        this->next=NULL;
        this->prev=NULL;
    }
};
class myStack
{
    public:
    Node* head=NULL;
    Node* tail=NULL;
    int sz=0;
    void push(int val)
    {
        sz++;
        Node* newnode=new Node(val);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
            return;
        }
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;//same to tail=tail->next;
    }
    void pop()
    {
        sz--;
        tail=tail->prev;
        if(tail==NULL)
        head=NULL;
        else
        tail->next=NULL;
    }
    int top()
    {
        return tail->value;
    }
    bool empty()
    {
       if(sz==0) return true;
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