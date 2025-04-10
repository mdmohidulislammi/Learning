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
void input_linked_list(Node *&head, Node *& tail, int value)
{
    Node *newnode=new Node(value);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        return;
    }
    tail->next=newnode;
    tail=newnode;
}
int main()
{
    Node*head=NULL;
    Node*tail=NULL;
    int value;
    while(true)
    {
        cin>>value;
        if(value==-1)break;
        input_linked_list(head,tail,value);
    }
    int mx=INT_MIN;
    for(Node*i=head;i->next!=NULL;i=i->next)
    {
        mx=max(mx,i->num);
    }
    cout<<mx;
    return 0;
}