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
void input_linked_list(Node *&head,Node *&tail,int val)
{
    Node*newnode=new Node(val);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        return;
    }
    tail->next=newnode;
    tail=newnode;
}
void mx_mn_fun(Node *head)
{
    int mx=INT_MIN;
    int mn=INT_MAX;
    Node *tmp=head;
    while(tmp!=NULL)
    {
        mx=max(tmp->num,mx);
        mn=min(tmp->num,mn);
        tmp=tmp->next;
    }
    cout<<mx-mn;
}
int main()
{
    Node *head=NULL;
    Node *tail=NULL;
    int value;
    while(true)
    {
        cin>>value;
        if(value==-1)break;
        input_linked_list(head,tail,value);
    }
    mx_mn_fun(head);    
    return 0;
}