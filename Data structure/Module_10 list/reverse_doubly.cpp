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
void input_linked_list(Node *&head,Node *&tail,int val)
{
    Node*newnode=new Node(val);
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

void reverse_doubly(Node* head, Node*tail)
{
    Node* i=head;
    Node* j=tail;
    while (i!=j && i->next!=j)
    {
        swap(i->value,j->value);
        i=i->next;
        j=j->prev;
    }
    swap(i->value,j->value);    
}
void print_linked_list(Node*head,Node*tail)
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
    while(true)
    {
     cin>>val;
     if(val==-1)break;
     input_linked_list(head,tail,val);
    }
    reverse_doubly(head,tail);
    print_linked_list(head,tail);
    return 0;
}