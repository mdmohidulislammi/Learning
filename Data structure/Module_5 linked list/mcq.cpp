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
int main()
{
    Node *head=new Node(10);
    Node* a=new Node(20);
    Node *b=new Node(30);
    Node *c=new Node (40);
    head->next=a;
    head->next->next=b;
    head->next->next->next=c;
    cout<<head->num<<endl;
    cout<<head->next->num<<endl;
    cout<<head->next->next->num<<endl;
    cout<<head->next->next->next->num<<endl;  
    return 0;
}