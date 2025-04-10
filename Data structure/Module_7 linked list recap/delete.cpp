#include<bits/stdc++.h>
using namespace std;
class Node
{
  public:
        int val;
        Node *next;
        Node(int val)
        {
            this->val=val;
            this->next=NULL;
        }
};
void delete_node(Node*head, int pos)
{
    Node*tmp=head;
    for(int i=1;i<pos;i++)
    {
        tmp=tmp->next;
    }
    Node *deletenode=tmp->next;
    tmp->next=tmp->next->next;
    delete deletenode;
}
void delete_head(Node*&head)
{
    Node*deletehead=head;
    head=head->next;
    delete deletehead;
}

int print_linked_list(Node *head)
{
    cout<<"Linked list :";
    int cnt=0;
    Node *tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->next;
        cnt++;
    }
    return cnt;
}
int main()
{
    //wihtout constructor and dynamic;
    // Node a=10,b=20;
    // a.next=&b;
    // cout<<a.val<<endl<<a.next->val<<endl;
    Node *head=new Node(10);
    Node *a=new Node(20);
    Node *b=new Node(30);
    Node *c=new Node(40);
    Node *d=new Node(50);
    // head->next=a;
    // a->next=b;
    // b->next=c;  
    // c->next=d;
    head->next=a;
    head->next->next=b;
    head->next->next->next=c;
    head->next->next->next->next=d;
    Node* tail=d;
    int position;
    cin>>position;
    if(position>=print_linked_list(head))
    {
        print_linked_list(head);
        cout<<"Invalid ";
    }
    else if(position==0)
    {
        delete_head(head);
         print_linked_list(head);
    }
    else 
    {
       delete_node(head,position);
       print_linked_list(head);
    }
    return 0;
}