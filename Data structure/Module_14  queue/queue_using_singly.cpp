#include<bits/stdc++.h>
using namespace std;
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
class myQueue
{
    public:
          Node* head=NULL;
          Node * tail=NULL;
          int sz=0;
          void push(int val)
          {
            sz++;
            Node* newnode=new Node(val);
            if(head==NULL)
            {
                head=newnode;
                tail=newnode;
                return;
            }
            tail->next=newnode;
            tail=newnode;
          }
          int front()
          {
            return head->num;
          }
          void pop()
          {
            sz--;
            head=head->next;
            if(head==NULL)
            {
                tail=NULL;
            }
          }
          int size()
          {
            return sz;
          }         
          bool empty()
          {
            if(sz==0) return true;
            else return false;
          }
};
int main()
{
    myQueue qu;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        qu.push(value);
    }
    while(!qu.empty())
    {
        cout<<qu.front()<<endl;
        qu.pop();
    }
    return 0;
}