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
void search_value(Node *head,int val)
{
    Node*tmp=head;
    int cnt=-1;
    bool flag=false;
    while(tmp!=NULL)
    {
        cnt++;
        if(tmp->num==val)
        {
            flag=true;
            break;
        }
        tmp=tmp->next;
    }
    if(flag==true)cout<<cnt<<endl;
    else cout<<"-1"<<endl;
}
int main()
{
    Node *head=NULL;
    Node *tail=NULL;
    int value;
    int test;
    cin>>test;
    for(int i=0;i<test;i++)
    {
         while(true)
    {
        cin>>value;
        if(value==-1)break;
        input_linked_list(head,tail,value);
    }
    int val;
    cin>>val;
    search_value(head,val);
    head=NULL;
    tail=NULL;
    }   
    return 0;
}