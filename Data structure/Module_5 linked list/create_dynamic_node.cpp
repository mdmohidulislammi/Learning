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
    Node *a=new Node(20);
    Node *b=new Node(30);
    head->next=a;
    a->next=b;
    cout<<head->num<<endl;
    cout<<head->next->num<<endl;
    cout<<a->next->num<<endl;  
    return 0;
}