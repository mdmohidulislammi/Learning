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
int main()
{
    Node *head=NULL;
    while(true)
    {
        cout<<"Option 1: Insert at tail : "<<endl;
        cout<<"Option 2: Insert at any position except 0 : "<<endl;
        cout<<"Option 3: Print linked list : "<<endl;
        cout<<"Option 4: Terminate program "<<endl<<endl<<endl;
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
        insert_at_poition(head, position, value);
       }
       else if(option==3)
       {
        cout<<endl<<endl<<"Linked list : "<<endl;
        print_linked_list(head);
       }
       else if(option==4)
       break;
    }    
    return 0;
}