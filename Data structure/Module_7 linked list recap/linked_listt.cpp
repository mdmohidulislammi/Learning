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
void print_linked_list(Node *head)
{
    cout<<"Linked list :";
    Node *tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }

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
    print_linked_list(head);
    return 0;
}