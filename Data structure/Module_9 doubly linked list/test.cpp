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
void input_list(Node*& head, Node*& tail, int val)
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
void delete_head(Node*& head, Node*& tail)
{
    Node* dl=head;
    head=head->next;
    delete dl;
    if(head==NULL)
    {
        tail=NULL;cout<<"Deleted head";
        return;
    }
    head->prev=NULL;
}
void delete_tail(Node*& tail,Node*& head)
{
    Node* dl=tail;
    tail=tail->prev;
    delete dl;
    if(tail==NULL)
    {
        head=NULL;cout<<"Deleted tail";
        return;
    }
    tail->next=NULL;
}
void print(Node*head)
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
   int value;
   while(1)
   {
    cin>>value;
    if(value==-1) break;
    input_list(head, tail, value);
   }
   delete_head(head,tail);
  /// delete_tail(tail,head);
   print(head );
    return 0;
}