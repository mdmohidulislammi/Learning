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
int main()
{
   Node* head=new Node(10);
   Node*a=new Node(20);
   Node*b=new Node(30);
   Node* c=new Node(40);
   Node* d=new Node(50);
   head->next=a;
   a->next=b;
   b->next=c;
   c->next=d;
   d->next=a;
   bool flag=false;
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        if(fast==slow)
        {
            flag=true;
            break;
        }
    }
    if(flag==true)cout<<"Detect";
    else cout<<"No cycle";
    return 0;
}