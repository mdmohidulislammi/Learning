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
void insert_head(Node*& head,Node*& tail, int val)
{
    Node* newnode=new Node(val);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        return;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

void insert_tail(Node*& head, Node*& tail, int val)
{
    Node* newnode=new Node(val);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        return;
    }
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
}
int size(Node*head)
{
    int cnt=0;
    while(head!=NULL)
    {
        cnt++;
        head=head->next;
    }
    return cnt;
}
void insert_pos(Node* head , int pos, int val)
{
    Node* tmp=head;
    Node* newnode=new Node(val);
    for(int i=1;i<pos;i++)
    {
           tmp=tmp->next;
    }
    newnode->next=tmp->next;
    newnode->prev=tmp;
    newnode->next->prev=newnode;
    tmp->next=newnode;
}
void print_doubly(Node*head, Node* tail)
{
     while(head!=NULL)
     {
        cout<<head->value<<" ";
        head=head->next;
     }
     cout<<endl;
     while (tail!=NULL)
     {
        cout<<tail->value<<" ";
        tail=tail->prev;
     }
     cout<<endl;     
}
int main()
{
    Node*head=NULL;
    Node* tail=NULL;
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int pos,val;
        cin>>pos>>val;
        if(pos==0)
        {
            insert_head(head,tail, val);
            print_doubly(head,tail);
        }
        else if(pos==size(head))
        {
            insert_tail(head,tail, val);
             print_doubly(head,tail);
        }
        else if(pos<size(head))
        {
            insert_pos(head, pos, val);
             print_doubly(head,tail);
        }
        else
        {
            cout<<"Invalid"<<endl;
        }
    }
    return 0;
}