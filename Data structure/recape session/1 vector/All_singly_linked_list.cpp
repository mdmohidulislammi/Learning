#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
      int data;
      Node *next;

      Node(int data)
      {
        this->data=data;
        next=NULL;
      }
};
void insert_at_head(Node* &head, int value)
{
    Node* newNode=new Node(value);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    newNode->next=head;
    head=newNode;
}
void insert_at_tail(Node*& head, Node*& tail, int value)//O(1)
{
    Node* newNode=new Node(value);
    if(head==NULL)
    {
        head=tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}
// void insert_at_tail(Node*& head,int value) //O(N)
// {
//     Node* newNode=new Node(value);
//     if(head==NULL)
//     {
//         head=newNode;
//         return;
//     }
//     Node*tmp=head;
//     while(tmp->next!=NULL)
//     {
//         tmp=tmp->next;
//     }
//     tmp->next=newNode;
// }
void insert_at_pos(Node*& head, int pos, int value)
{
    Node* newNode=new Node(value);
    Node* temp=head;
    for(int i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }    
    if(temp==NULL)
    {
        head=newNode;
        return;
    }
    if(temp->next==NULL)
    {
        newNode->next=head;
        head=newNode;
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    while(1)
    {
        int operation;
        cin>>operation;
        if(operation==1)
        {
            int value;
            cin>>value;
            insert_at_head(head,value);            
        }
        else if(operation==2)
        {
            int value;
            cin>>value;
            insert_at_tail(head,tail,value);//O(1)
           // insert_at_tail(head,value);
        }
        else if(operation==3)
        {
            int value,pos;
            cin>>pos>>value;
            insert_at_pos(head,pos,value);
        }
        else if(operation==4)
        {
            //delete_at_head(head);
        }
        else if(operation==5)
        {
          //  delete_at_tail(head,tail);
        }
        else if(operation==6)
        {
           // delete_at_pos(head);
        }
        else if(operation==99)
        break;
    }
    print(head);
    return 0;
}