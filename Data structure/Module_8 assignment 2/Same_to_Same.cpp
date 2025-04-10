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
int cntfun(Node* head)
{
    int cnt=0;
    Node*tmp=head;
    while(tmp!=NULL)
    {
        cnt++;
        tmp=tmp->next;
    }return cnt;
}
int cnfun(Node* head)
{
    int cnt=0;
    Node*tmp=head;
    while(tmp!=NULL)
    {
        cnt++;
        tmp=tmp->next;
    }return cnt;
}
int main()
{
    Node *head=NULL;
    Node* head1=NULL;
    Node *tail=NULL;
    int value;
    while(true)
    {
        cin>>value;
        if(value==-1)break;
        input_linked_list(head,tail,value);
    }
    while(true)
    {
        cin>>value;
        if(value==-1)
        break;
        input_linked_list(head1,tail,value);
    }
    int flag=0;
    int cnt=cntfun(head);
    int cn=cnfun(head1);   
    Node* tmp=head;
    Node*tmp1=head1;
    if(cnt==cn)
    {
       while(tmp!=NULL)
       {
        if(tmp->num!=tmp1->num)
        {
            flag=1;
        }
        tmp=tmp->next;
        tmp1=tmp1->next;
       }
    }
   if(cnt!=cn)
   cout<<"NO";
   else if(flag==1)
   cout<<"NO";
   else if(flag==0)
   cout<<"YES"; 
    return 0;
}