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
    Node* tmp=head;    
   for(Node*i=tmp;i!=NULL;i=i->next)
   {
    //cout<<i->num<<" ";
    for(Node*j=i;j->next!=NULL;)
    {
        if(j->next->num==i->num)
        {
           j->next=j->next->next;
        }
        else
        j=j->next;
    }
  }  
   print_linked_list(head);    
    return 0;
}