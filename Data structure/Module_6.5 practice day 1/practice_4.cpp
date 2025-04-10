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
void input_linked_list(Node *&head,int val)
{
    Node *newnode=new Node(val);
    Node *tmp=head;
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    while (tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=newnode;    
}

void print_linked_list(Node*head)
{
    Node*tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->num<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}
void insert_position(Node *&head,int pos,int val)
{
    Node*tmp=head;
    Node*t=head;
    Node *newnode=new Node(val);
    if(pos==0)
    {
       newnode->next=head;
       head=newnode;
       print_linked_list(head);
       return ;
    }
    for(int i=1;i<pos;i++)
    {
        tmp=tmp->next;
        if(tmp==NULL)
        {
            cout<<"Invalid"<<endl;
            return ;
        }      
    }      
    newnode->next=tmp->next;
    tmp->next=newnode;   
    print_linked_list(head); 
}
int main()
{
    Node*head=NULL;
    int value;
    //cout<<"Enter your value: ";
    while (1)
    {
        cin>>value;
        if(value==-1)
        {
            break;
        }
        input_linked_list(head,value);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int pos,val;
        cin>>pos>>val;
        insert_position(head,pos,val);
    }    
    return 0;
}