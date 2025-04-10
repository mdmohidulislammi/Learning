#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int num;
    Node* next;
    Node(int num)
    {
        this->num=num;
        this->next=NULL;
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
    tail=newnode;
}
void reverse_singly(Node*& head, Node *cur)
{
   if(cur->next==NULL)
   {
      head=cur;
      return;
   }
   reverse_singly(head,cur->next);
   cur->next->next=cur;
   cur->next=NULL;
}
void print_linked_list(Node *head)
{
    Node *tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->num<<" ";
        tmp=tmp->next;
    }
}
int main()
{
    Node *head=NULL;
    Node *tail=NULL;
    int value;
    while(true)
    {
        cin>>value;
        if(value==-1)break;
        input_linked_list(head,tail,value);
    }
    reverse_singly(head,head);
    print_linked_list(head);    
    return 0;
}