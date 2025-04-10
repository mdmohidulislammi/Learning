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
void input_linked_list(Node *&head, int value)
{
    Node*tmp=head;
    Node *newnode=new Node(value);
    if(head==NULL)
    {
        head=newnode;
        return ;
    }
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=newnode;
}

int main()
{
    Node* head=NULL;
    int value;
    while (true)
    {
       cin>>value;
       if(value==-1)
       break;
       input_linked_list(head,value);
    }
    bool flag=true;
    Node*tmp=head;
    for(Node*i=tmp;i->next!=NULL;i=i->next)  
    {
        for(Node*j=i->next;j!=NULL;j=j->next)
        {
            if(i->num>j->num)
            flag=false;
        }
    }  
    if(flag==true) cout<<"YES";
    else cout<<"NO";
    return 0;
}