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
void insert_head(Node*& head, int val)
{
    Node* newnode=new Node(val);
          if(head==NULL)
          {
            head=newnode;
            return;
          }
        newnode->next=head;
        head=newnode;
}
void insert_tail(Node *&head, int val)
{
      Node* tmp=head;
      if(head==NULL)
      {
        insert_head(head,val);
        return;
      }
      Node *newnode=new Node(val);
      while(tmp->next!=NULL)
      {
        tmp=tmp->next;
      }
      tmp->next=newnode;
}
void delete_from_pos(Node*& head, int val)
{
    Node* tmp=head;
    if(head==NULL)
    {
        return;
    }
    if(val==0)
    {
        Node* deletehead=head;
        head=head->next;
        delete deletehead;
        return ;
    }
    for(int i=1;i<val;i++)
    {
        
        tmp=tmp->next;
        if(tmp==NULL)
        {
            return;
        }
    }   
    if(tmp->next==NULL)
    {
        return ;
    }
    Node *deletenode=tmp->next;
    tmp->next=tmp->next->next;
    delete deletenode;
}
void print_linked_list(Node *head)
{
    Node *tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->num<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}
int main()
{
    Node *head=NULL;
    int q,n,val;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>n>>val;
        if(n==0)
        {
            insert_head(head,val);
            print_linked_list(head);
        }
        else if(n==1)
        {
            insert_tail(head,val);
            print_linked_list(head);
        }
        else
        {
            delete_from_pos(head,val);
            print_linked_list(head);
        }
    }
    return 0;
}