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
//insert at tail
void insert_at_tail(Node *&head, int val)
{
    Node *tmp=head;
    Node * newnode=new Node(val);
    if(head==NULL)
    {
        head=newnode;
        cout<<"inserted at head"<<endl;
        return ;
    }
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=newnode;
    cout<<endl<<"inserted at tail"<<endl;
}
//insert at head
void insert_at_head(Node *& head, int val)
{
    Node *newnode=new Node(val);
    newnode->next=head;
    head=newnode;
    cout<<endl<<"inserted at head"<<endl;
}
//insert at any position.
void insert_at_any_position(Node*head, int position, int value)
{
    Node *tmp=head;
    Node*newnode=new Node(value);
    for(int i=1;i<position;i++)
    {
        tmp=tmp->next;
        if(tmp==NULL)
        {
            cout<<endl<<"Invalid index."<<endl;
            return;
        }
    }    
    newnode->next=tmp->next;
    tmp->next=newnode;
    cout<<"Insert at given position ."<<endl;
}
//delete at any position.
void delete_at_position(Node * head, int pos)
{
    Node * tmp=head;
    for(int i=1;i<pos;i++)
    {
        tmp=tmp->next;
        if(tmp==NULL)
        {
            cout<<endl<<"Invalid index"<<endl;
            return;
        }
    }
    if(tmp->next==NULL)
    {
        cout<<endl<<"Invalid index"<<endl;
        return ;
    }
    Node*delete_node=tmp->next;
    tmp->next=tmp->next->next;
    delete delete_node;
}
//delete form head .
void delete_from_head(Node*&head)
{
   Node*delete_head=head;
   head=head->next;
   delete delete_head;
}
//print  linked list //
void print_linked_list(Node *head)
{
    Node *tmp=head;
    cout<<"Your linked List: ";
    while(tmp!=NULL)
    {
        cout<<tmp->num<<" ";
        tmp=tmp->next;
    }
}

//start main function
//start main function
int main()
{
    Node *head=NULL;
    while(true)
    {
        cout<<endl<<"Option 1: Insert at tail ."<<endl;
        cout<<"Option 2: Insert at head ."<<endl;
        cout<<"Option 3: Insert at any position ."<<endl;
        cout<<"Option 4: Delete at any position ."<<endl;
        cout<<"Option 5: Delete from head ."<<endl;
        cout<<"Option 0: Print Linked List."<<endl;
        cout<<"Last Option: exit 99 to terminate program for enter."<<endl;
        int op;
        cin>>op;
        if(op==1)
        {
            int val;
            cin>>val;
            insert_at_tail(head, val);
        }
        else if(op ==2)
        {
            int val;
            cin>>val;
            insert_at_head(head,val);
        }
        else if(op==3)
        {
            int position,val;
            cout<<"Enter position: ";
            cin>>position;
            cout<<"Enter value :";
            cin>>val;
            insert_at_any_position(head,position,val);
        }
        else if(op==4)
        {
            int pos;
            cout<<endl<<"Enter position :";
            cin>>pos;
            delete_at_position(head,pos);
        }
        else if(op==5)
        {
            delete_from_head(head);
        }
        else if(op==0)
        {
            print_linked_list(head);
        }
        else if(op==99)
        {
            print_linked_list(head);
            break;
        }
    }  
    return 0;
}