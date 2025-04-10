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
void insert_tail(Node*& head, Node*& tail, int value)
{
      Node* newnode=new Node(value);
      if(tail==NULL)
      {
        head=newnode;
        tail=newnode;
        return;
      }
      tail->next=newnode;
      newnode->prev=tail;
      tail=newnode;
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
int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    int val;
    while(1)
    {
        cin>>val;
        if(val==-1)break;
        insert_tail(head, tail, val);
    }
    print(head, tail);
    return 0;
}