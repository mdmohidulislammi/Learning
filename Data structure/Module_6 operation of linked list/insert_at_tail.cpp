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
    Node * new_node=new Node(v);
    if(head==NULL)
    {
        head = new_node;
        return;
    }
    Node* tmp = head;
    while(tmp->next!=NULL)
    {
       tmp=tmp->next;
    }//tmp last node e.
    tmp->next=new_node;
}
void print_linked_list(Node *head)
{
    Node* tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->num<<" ";
        tmp=tmp->next;
    }
}
int main()
{
    Node *head=NULL;
    while(true)
    {
        //cout<<"1. Insert at tail: ";
        int op;
        cin>>op;
        if(op==1)
        {
            cout<<"Enter a value for linked list: ";
            int v;
            cin>>v;
            insert_at_tail(head , v);
        }
        else if(op==2)
        {
            print_linked_list(head);

        }
        else if(op==3)
        {
            break;
        }
    }  
    return 0;
}