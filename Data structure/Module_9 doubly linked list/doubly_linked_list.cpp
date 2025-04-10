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
void print(Node*head, Node*b)
{
    Node*tmp=head;
    Node* tmp1=b;
    while(tmp!=NULL)
    {
        cout<<tmp->value<<" ";
        tmp=tmp->next;
    }cout<<endl;
    while(tmp1!=NULL)
    {
        cout<<tmp1->value<<" ";
        tmp1=tmp1->prev;
    }
}
int main()
{
    Node* head =new Node (10);
    Node* a=new Node(20);
    Node *b=new Node(30);
    Node* tail=b;
    head->next=a;
    a->prev=head;
    a->next=b;
    b->prev=a;
    print(head,b);
    return 0;
}