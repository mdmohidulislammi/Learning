#include<bits/stdc++.h>
using namespace std;
class Node
{
  public:
        int val;
        Node *next;
        Node(int val)
        {
            this->val=val;
            this->next=NULL;
        }
};
void insert_position(Node *head, int pos,int val)
{
    Node*newnode=new Node(val);
    Node*tmp=head;
    for(int i=1;i<pos;i++)
    {
        tmp=tmp->next;
    }
    newnode->next=tmp->next;
    tmp->next=newnode;
}
void insert_at_head(Node* &head, int val)
{
    Node*newnode=new Node(val);
    newnode->next=head;
    head=newnode;
}
void insert_at_tail(Node *&head, Node*&tail,int val)
{
   Node*newnode=new Node (val);
   if(head==NULL)
   {
      newnode->next=head;
      head=newnode;
   }
   else
   {
    tail->next=newnode;
    tail=newnode;
   }
}
int print_linked_list(Node *head)
{
    cout<<"Linked list :";
    int cnt=0;
    Node *tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->next;
        cnt++;
    }
    return cnt;
}
int main()
{
    //wihtout constructor and dynamic;
    // Node a=10,b=20;
    // a.next=&b;
    // cout<<a.val<<endl<<a.next->val<<endl;
    Node *head=new Node(10);
    Node *a=new Node(20);
    Node *b=new Node(30);
    Node *c=new Node(40);
    Node *d=new Node(50);
    // head->next=a;
    // a->next=b;
    // b->next=c;  
    // c->next=d;
    head->next=a;
    head->next->next=b;
    head->next->next->next=c;
    head->next->next->next->next=d;
    Node* tail=d;
    int position;
    cin>>position;
    if(position>print_linked_list(head))
    {
        cout<<"Invalid Index"<<endl;
    }
    else if(position==0)
    {

        int value;
        cin>>value;
       insert_at_head(head,value);
    }
    else if(position==print_linked_list(head))
    {
        int value;
        cin>>value;
        insert_at_tail(head,tail,value);
    }
    else
    {
        int value;
        cout<<endl<<"Enter value: ";
        cin>>value;
        insert_position(head,position,value);
    }
    print_linked_list(head);
    return 0;
}