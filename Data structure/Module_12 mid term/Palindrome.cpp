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
void input_linked(Node*& head, Node*& tail, int val)
{
    Node* newnode =new Node(val);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        return;
    }
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
}
void palindrome_doubly(Node* head, Node* tail)
{
    bool flag=true;
    Node* tmp=head;
    Node* tmp1=tail;
    while(tmp!=NULL)
    {
        if(tmp->value!=tmp1->value)
        flag=false;
        tmp=tmp->next;
        tmp1=tmp1->prev;
    }
    if(flag==true) cout<<"YES";
    else cout<<"NO";
}
int main()
{
    Node*head=NULL;
    Node* tail=NULL;
    int val;
    while(true)
    {
        cin>>val;
        if(val==-1)break;
        input_linked(head,tail,val);
    }
    palindrome_doubly(head,tail);
    return 0;
}