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
void insert_at_tail(Node*& hd, int val)
{
   Node* tmp=hd;
   Node * newnode=new Node(val);
   if(hd==NULL)
   {
    hd=newnode;
    return ;
   }
   while(tmp->next!=NULL)
   {
    tmp=tmp->next;
   }
   tmp->next=newnode;
}
void print_linked_list(Node *head)
{
    int cnt=0,freq[100]={0};
    cout<<"Your Linked list : ";
    Node*tmp=head;
    while(tmp!=NULL)
    {
        freq[tmp->num]++;
        cout<<tmp->num<<" ";
        tmp=tmp->next;
        cnt++;
    }
    bool flag=false;
    for(int i=0;i<100;i++)
    {
        if (freq[i]>=2)
        {
            flag=true;
        }
    }
    cout<<endl<<"Size of your linked list: "<<cnt<<endl;
    if(flag==true)
    cout<<"Yes"<<endl;
    else cout<<"NO";
}
int main()
{
    Node * head=NULL;
    int value;
    cout<<"Enter your value for linked list: ";
    while (true )
    {
        cin>>value;
        if(value==-1)
        {
            print_linked_list(head);
            break;
        }
        else
        {
            insert_at_tail(head,value);
        }
    }
    return 0;
}