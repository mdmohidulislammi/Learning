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
void input_linked_list(Node *&head, Node *& tail, int value)
{
    Node *newnode=new Node(value);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        return;
    }
    tail->next=newnode;
    tail=newnode;
}
void print_descending_order(Node*head)
{
   Node*tmp=head;
   while(tmp!=NULL)
   {
    cout<<tmp->num<<" ";
    tmp=tmp->next;
   }
}
int main()
{
    Node*head=NULL;
    Node*tail=NULL;
    int value;
    while(true)
    {
        cin>>value;
        if(value==-1)break;
        input_linked_list(head,tail,value);
    }
    
    for(Node*i=head;i->next!=NULL;i=i->next)
    {
        for(Node*j=i->next;j!=NULL;j=j->next)
        {
            if(i->num<j->num)
            swap(i->num,j->num);
        }
    }
    print_descending_order(head);
    return 0;
}