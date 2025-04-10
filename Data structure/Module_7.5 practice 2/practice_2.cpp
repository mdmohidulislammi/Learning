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
void input_linked_list(Node*&head,Node *&tail, int value)
{
    Node*tmp=head;
    Node* newnode=new Node(value);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        return ;
    }
    tail->next=newnode;
    tail=newnode;
    // while(tmp->next!=NULL)
    // {
    //     tmp=tmp->next;
    // }
    // tmp->next=newnode;
}
void print_linked_reverse(Node*head)
{
    Node*tmp=head;
    if(tmp==NULL) return ;
    print_linked_reverse(tmp->next);
    cout<<tmp->num;
}
int main()
{
    Node*head=NULL;
    Node*tail=NULL;
    int value;
    while(1)
    {
        cin>>value;
        if(value==-1)break;
        input_linked_list(head,tail,value);
    }
    print_linked_reverse(head);
    return 0;
}