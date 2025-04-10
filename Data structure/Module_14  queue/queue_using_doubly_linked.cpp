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
class myQueue
{
    public:
        Node* head=NULL;
        Node* tail=NULL;
        int sz=0;
        void push(int val)
        {
            sz++;
            Node* newNode=new Node(val);
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
        void pop()
        {
            sz--;
            head=head->next;            
            if(head==NULL)
            {
                tail=NULL;
                return;
            }
            head->prev=NULL;
        }
        int front()
        {
            return head->value;
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
    // qu.pop();
    // cout<<qu.front();
    // cout<<qu.front();
    while(!qu.empty())
    {
        cout<<qu.front()<<endl;
        qu.pop();
    }
    return 0;
}