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
class st
{
    public:
    Node* head=NULL;
    Node* tail=NULL;
    int sz=0;
    void push(int value)
    {
        sz++;
        Node* newNode=new Node(value);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
            return ;
        }
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
    }
    void pop()
    {
        sz--;
        tail=tail->prev;
        if(tail==NULL)
        {
            head==NULL;
            return;
        }        
        tail->next=NULL;
    }   
    int top()
    {
        return tail->value;
    }
    // int size()
    // {
    //     return sz;
    // }
    bool empty()
    {
        if(sz==0) return true;
        else return false;
    }
};
int main()
{
    st st1,st2;
    int t1,t2;    
    cin>>t1; 
    for(int i=0;i<t1;i++)
    {
        int value;
        cin>>value;
        st1.push(value);
    }
    cin>>t2;
    for(int i=0;i<t2;i++)
    {
        int value;
        cin>>value;
        st2.push(value);
    }
    int flag=1;
    if(t1==t2)
    {
       while(!st1.empty() && !st2.empty())
       {
        if(st1.top() != st2.top())
        {
            flag=0;
            break;
        }
        st1.pop();
        st2.pop();
       }
    }  
    if(t1!=t2)
    cout<<"NO";
    else if(flag==0) cout<<"NO";
    else cout<<"YES"; 
    return 0;
}