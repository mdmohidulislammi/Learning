#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
          int data;
          Node *next;
          Node(int data)
          {
            this->data=data;
            this->next=NULL;
          }
};
void input_snode(Node* &head,Node*& tail, int value)
{
    Node* newNode=new Node(value);
    if(head==NULL)
    {
       head=newNode;
       tail=newNode;
       return ;
    }
    tail->next=newNode;  
    tail=newNode;  
}
void output_snode(Node* head)
{
    Node* tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
}
int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    while(true)
    {
        int value;
        cin>>value;
        if(value==-1) break;
        input_snode(head,tail,value);
    }
    output_snode(head);
    return 0;
}