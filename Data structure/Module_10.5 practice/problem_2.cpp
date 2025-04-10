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
void reverse_linked(Node* head, Node *tail)
{
    Node* tmp=head;
    Node*tmp1=tail;
    while(tmp!=tmp1 && tmp->next!=tmp1)
    {
        swap(tmp->value,tmp1->value);
        tmp=tmp->next;
        tmp1=tmp1->prev;
    }
    swap(tmp->value,tmp1->value);
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
    Node* head=NULL;
    Node* tail=NULL;
    int val;
    while(1)
    {
        cin>>val;
        if(val==-1)break;
        input_linked(head, tail,val);
    }
  reverse_linked(head, tail);
  print(head);
    return 0;
}