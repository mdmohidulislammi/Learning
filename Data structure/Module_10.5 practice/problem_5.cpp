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
void input_linked(Node*& head, Node*& tail, int val)
{
    Node* newnode =new Node(val);
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
void ascending_order(Node* head)
{
    for(Node* i=head;i->next!=NULL;i=i->next)
    {
        for(Node* j=i->next;j!=NULL;j=j->next)
        {
            if(i->value>j->value)
            swap(i->value,j->value);
        }
    }
}
void print(Node* head)
{
  while(head!=NULL)
  {
    cout<<head->value<<" ";
    head=head->next;
  }
}
int main()
{
    Node*head=NULL;
    Node* tail=NULL;
    int val;
    while(true)
    {
        cin>>val;
        if(val==-1)break;
        input_linked(head,tail,val);
    }
    ascending_order(head);
    print(head);
    return 0;
}