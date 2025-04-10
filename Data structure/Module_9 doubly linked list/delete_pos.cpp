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
void delete_head(Node*& head, Node*& tail)
{
    Node* dl=head;
    head=head->next;
    delete dl;
    if(head==NULL)
    {
        tail=NULL;
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
        head=NULL;
        return;
    }
    tail->next=NULL;
}
void delete_pos(Node* head, int pos)
{
    Node* tmp=head;
    for(int i=1;i<pos;i++)
    {
        tmp=tmp->next;
    }
    Node* dl=tmp->next;
    tmp->next=tmp->next->next;   
    tmp->next->prev=tmp;

     delete dl;
}
void print(Node*head, Node*tail)
{
    Node*tmp=head;
    Node* tmp1=tail;
    while(tmp!=NULL)
    {
        
        cout<<tmp->value<<" ";
        tmp=tmp->next;
    }cout<<endl;
    while(tmp1!=NULL)
    {
        cout<<tmp1->value<<" ";
        tmp1=tmp1->prev;
    }   
}
int size(Node* head)
{
    int cnt =0;
    while(head!=NULL)
    {
        cnt++;
        head=head->next;
    }
    return cnt;
}

int main()
{
    Node* head =new Node (10);
    Node* a=new Node(20);
    Node *b=new Node(30);
    Node *c=new Node(40);
    Node* tail=c;
    head->next=a;
    a->prev=head;
    a->next=b;
    b->prev=a;
    b->next=c;
    c->prev=b;
   int pos;
   cin>>pos;
   if(pos==0)
   {
     delete_head(head,tail);
   }
   else if(pos==size(head)-1)
   {
     delete_tail(tail,head);
   }
   else if(pos<size(head))
   {
      delete_pos(head,pos);
   }
   else cout<<"Invalid index"<<endl;
    print(head,tail);
    return 0;
}