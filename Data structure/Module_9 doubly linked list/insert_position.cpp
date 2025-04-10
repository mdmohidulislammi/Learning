#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
    int value;
    Node* next;
    Node * prev;
    Node(int value)
    {
        this->value=value;
        this->next=NULL;
        this->prev=NULL;
    }
};
void insert_at_position(Node*head, int pos, int value)
{
    Node*tmp=head;
    Node * newnode=new Node(value);
    for(int i=1;i<pos;i++)
    {
        tmp=tmp->next;
    }
    newnode->next=tmp->next;
    tmp->next=newnode;
    newnode->prev=tmp;
    newnode->next->prev=newnode;
}
int print(Node*head, Node*b)
{
    int cnt=0;
    Node*tmp=head;
    Node* tmp1=b;
    while(tmp!=NULL)
    {
        cnt++;
        cout<<tmp->value<<" ";
        tmp=tmp->next;
    }cout<<endl;
    // while(tmp1!=NULL)
    // {
    //     cout<<tmp1->value<<" ";
    //     tmp1=tmp1->prev;
    // }
    return cnt;
}
int main()
{
    Node* head =new Node (10);
    Node* a=new Node(20);
    Node *b=new Node(30);
    Node *c=new Node(40);
    Node* tail=c;
    head->next=a;
    a->prev=head;
    a->next=b;
    b->prev=a;
    b->next=c;
    c->prev=b;
    int pos, val;
    cin>>pos>>val;
    if(pos>=print(head,tail))
    {
        cout<<"invalid"<<endl;
    }
    else 
    insert_at_position(head,pos,val);
    print(head,tail);
    return 0;
}