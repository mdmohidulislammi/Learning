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
void insert_at_tail(Node *&head, int v)
{
     Node*tmp=head;
     Node *newnode=new Node(v);
     if(head==NULL)
     {
         head=newnode;
         return;
     }
     while(tmp->next!=NULL)
     {
        tmp=tmp->next;
     }
     tmp->next=newnode;
     cout<<"Inserted at tail .";
}
void insert_at_poition(Node *head, int pos, int val)
{
    Node *tmp=head;
    Node *newnode=new Node(val);
    for(int i=1;i<pos;i++)
    {
        tmp=tmp->next;
    }
    newnode->next=tmp->next;
    tmp->next=newnode;
    cout<<"Inserted at position .";
}
void print_linked_list(Node * head)
{
    Node* tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->num<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}
void insert_at_head(Node * &head,int val)
{
    Node *newnode=new Node(val);   
    newnode->next=head;
    head=newnode;
    cout<<"Inserted at head.";
}
void delete_from_position(Node* head, int pos)
{
    Node* tmp=head;
    for(int i=1;i<pos;i++)
    {
        tmp=tmp->next;
    }
    Node *deletenode=tmp->next;
    tmp->next=tmp->next->next;
    delete deletenode;
}
void delete_head(Node* &head)
{
    Node* delete_head=head;
    head=head->next;
    delete delete_head;

}

// Here start main function;
// Here start main function;
// Here start main function;

int main()
{
    Node *head=NULL;
    while(true)
    {
        cout<<"Option 1: Insert at tail : "<<endl;
        cout<<"Option 2: Insert at any position except 0 : "<<endl;
        cout<<"Option 3: Print linked list : "<<endl;
        cout<<"Option 4: Insert at head : "<<endl;
        cout<<"Option 5: Delete position : "<<endl;
        cout<<"Option 6: Delete head "<<endl;
        cout<<"Option 7: Terminate program "<<endl<<endl;
        int option;
        cin>>option;
        if(option==1)
        {
            int v;
            cin>>v;
            insert_at_tail(head, v);
        }
       else if(option ==2)
       {
        cout<<"Enter positon : "<<endl;
        int position,value;
        cin>>position;
        cout<<"Enter value : ";
        cin>>value;
        if(position==0)
        {
            insert_at_head(head,value);
        }
        else
        insert_at_poition(head, position, value);
       }
       else if(option==3)
       {
        cout<<endl<<endl<<"Linked list : "<<endl;
        print_linked_list(head);
       }
       else if(option ==4 )
       {
        int val;
        cout<<"Enter val : ";
        cin>>val;
        insert_at_head(head,val);
       }
       else if(option ==5)
       {
        int pos;
        cout<<"Enter position:";
        cin>>pos;
        delete_from_position(head, pos);
       }
       else if(option==6)
       {
        delete_head(head);
       }
       else if(option==7)
       {
        cout<<"Print linked list : "<<endl;
        print_linked_list(head);
        break;
       }
    }    
    return 0;
}