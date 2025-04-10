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
void input_linked_list(Node*&head,Node*&tail, int val)
{
    //Node*tmp=head;
    Node *newnode=new Node(val);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        return ;
    }    
    tail->next=newnode;
    tail=newnode;
}
int size_linked(Node * head)
{
    int cnt=0;
    Node *tmp=head;
    while(tmp!=NULL)
    {
        tmp=tmp->next;
        cnt++;
    }
    return cnt;
}
void print_linked(Node*head)
{
    Node*tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->num<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}
int main()
{
    Node*head1=NULL;
    Node*head2=NULL;
    Node* tail=NULL;
    int value;
    while(1)
    {
        cin>>value;
        if(value==-1) break;
        input_linked_list(head1,tail,value);
    }
   // print_linked(head1);
    while(1)
    {
        cin>>value;
        if(value==-1)
        break;
        input_linked_list(head2,tail,value);
    }
  //print_linked(head2);
    int cn=size_linked(head1);
   int cnt=size_linked(head1);
   if(cn==cnt)cout<<"YES";
   else cout<<"NO";
    return 0;
}