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
       // cout<<"inserted at head"<<endl;
        return ;
    }
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=newnode;
   // cout<<endl<<"inserted at tail"<<endl;
}
//insert at head
void insert_at_head(Node *& head, int val)
{
    Node *newnode=new Node(val);
    newnode->next=head;
    head=newnode;
   // cout<<endl<<"inserted at head"<<endl;
}
//print  linked list //
int print_linked_list(Node *head)
{
    Node *tmp=head;
    int cnt=0;
    cout<<"Your linked List: ";
    while(tmp!=NULL)
    {
        cout<<tmp->num<<" ";
        tmp=tmp->next;
        cnt++;
    }
    return cnt;
}
int main()
{
    int n,cnt;
    Node*head =NULL;
    while(true)
    {
      cout<<"Input your value: ";
       cin>>n;
       if(n==-1)
       {
        cnt=print_linked_list(head);

        break;
       }
       insert_at_tail(head,n);
    }
    cout<<endl<<"The size of linked list: "<<cnt;
    return 0;
}