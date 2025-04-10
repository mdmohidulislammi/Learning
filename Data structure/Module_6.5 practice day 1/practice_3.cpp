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
void input_linked_list(Node *&head, int val)
{
    Node *newnode=new Node(val);
    Node *tmp=head;
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
int size_linked(Node* head)
{
    int cnt=0;
    Node *tmp=head;
    while(tmp!=NULL)
    {
       //cout<<tmp->num<<" ";
        tmp=tmp->next;
        cnt++;
    }
    return cnt;
}
void print_middle(Node*head,int cnt)
{
    Node*tmp=head;
    int mid=cnt/2;
    for(int i=1;i<=mid+1;i++)
    {
        if(cnt%2==0)
        {
            if(mid==i || mid+1==i)
            cout<<tmp->num<<" ";
        }
        else if(mid+1==i)
        {
            cout<<tmp->num;
        }
        tmp=tmp->next;
    }
}
int main()
{
    Node *head=NULL;    
    cout<<"Enter value :";
    int value;
    while (1)
    {
        cin>>value;
        if(value==-1)
        {
            break;
        }
        input_linked_list(head,value);
    }
   int cnt= size_linked(head); 
   print_middle(head,cnt);
    return 0;
}