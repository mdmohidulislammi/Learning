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
void palindrome(Node* head,Node* tail)
{
    bool flag=true;
    Node*i =head;
    Node* j=tail;
    while(i!=j && i->next!=j)
    {
        if(i->value!=j->value)
        flag=false;
        i=i->next;
        j=j->prev;
    }
    if(i->value!=j->value) flag=false;
    if(flag==true)
    cout<<"YES";
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
    palindrome(head,tail);
    return 0;
}