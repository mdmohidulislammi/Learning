#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
    int value;
    Node* next;
    Node* prev;
    Node(int value)
    {
        this->value=value;
        this->next=NULL;
        this->prev=NULL;
    }
};
void input_doubly(Node* &head, Node*& tail, int val)
{
    Node* newnode = new Node(val);
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
int size(Node* head)
{
    int cnt=0;
    while (head!=NULL)
    {
        cnt++;
        head=head->next;
    }
    return cnt;    
}
void compare_doubly(Node* head, Node* tail, Node *head1, Node* tail1,int cnt,int cn)
{
    bool flag=true;
    if(cnt==cn)
    {
        while(head!=NULL)
        {
            if(head->value!=head1->value)
           {
             flag=false;
           }
            head1=head1->next;
            head=head->next;
        }
    }
    if(cnt!=cn)cout<<"NO";
    else if(flag==false)cout<<"NO";
    else if(flag==true) cout<<"YES";
}
int main()
{
   Node* head=NULL;
   Node* head1=NULL;
   Node* tail=NULL;
   Node* tail1=NULL;
   int val;
   while(1)
   {
    cin>>val;
    if(val==-1)break;
    input_doubly(head,tail,val);
   }
    while(1)
   {
    cin>>val;
    if(val==-1)break;
    input_doubly(head1,tail1,val);
   }
    int cnt=size(head);
    int  cn=size(head1);
    compare_doubly(head,tail,head1,tail1,cnt,cn);  
    return 0;
}