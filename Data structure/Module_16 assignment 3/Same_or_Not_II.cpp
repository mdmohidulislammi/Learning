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
class mySt
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
            return;
        }
        newNode->prev=tail;
        tail->next=newNode;        
        tail=newNode;
    }
    int top()
    {
        return tail->value;
    }
    void pop()
    {
        sz--;
        tail=tail->prev;
        if(tail==NULL)
        {
            head=NULL;
            tail=NULL;
            return;
        }
        tail->next=NULL;
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
class myQueue
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
            return;
        }
        newNode->prev=tail;
        tail->next=newNode;        
        tail=newNode;
    }
    int front()
    {
        return head->value;
    }
    void pop()
    {
        sz--;
        head=head->next;
        if(head==NULL)
        {
            head=NULL;
            tail=NULL;
            return;
        }
        head->prev=NULL;
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
    mySt st;
    myQueue q;
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