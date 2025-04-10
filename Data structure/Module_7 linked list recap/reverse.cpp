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
void insert_at_tail(Node *&head, Node*&tail,int val)
{
   Node*newnode=new Node (val);
   if(head==NULL)
   {
      
      head=newnode;
      tail=newnode;
      return ;
   }
   tail->next=newnode;
   tail=newnode;
}
void print_reverse(Node *n)
{
    if(n==NULL) return ;
    print_reverse(n->next);
    cout<<n->num<<" ";
}
void print_recursion(Node *n)
{
    if(n==NULL) return ;
    
    cout<<n->num<<" ";
    print_recursion(n->next);
}
int main()
{
    Node *head=NULL;
    Node*tail=NULL;
    int value;
    while(true)
    {
        cin>>value;
        if(value==-1)break;
        insert_at_tail(head,tail,value);
    }
    print_recursion(head);
    cout<<endl;
    print_reverse(head);
    return 0;
}