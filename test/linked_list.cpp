#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next, *prev;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};
void input(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
void delete_tail(Node *&head, Node *&tail)
{
    tail = tail->prev;
    if (tail == NULL)
    {
        head = NULL;
        tail == NULL;
        return;
    }
    tail->next = NULL;
}
void delete_position(Node *&head, Node *&tail, int pos)
{
    Node *tmp = head;
    for (int i = 1; i < pos; i++)
    {
        tmp = tmp->next;
        if (tmp->next == NULL) // tail er next value delete korte chaile
            return;            // Invalid
    }
    if (tmp->prev == NULL) // It is head
    {
        head = head->next;
        head->prev = NULL;
        return;
    }
    tmp->next = tmp->next->next;
    if (tmp->next == NULL)
        return; // tail delete
    tmp->next->prev = tmp;
}
void insert_head(Node*& head, Node*& tail , int value)
{
    Node* newNode=new Node( value);
    if(head==NULL )
    {
        head=newNode;
        tail=newNode;
        return;
    }
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
}
void insert_at_position(Node *&head, Node *&tail, int pos, int value)
{
    Node *tmp = head;
    Node *newnode = new Node(value);
    for (int i = 1; i < pos; i++)
    {
        tmp = tmp->next;
    }
    if(tmp->prev==NULL) // it is head
    {        
        // head->prev=newnode;
         newnode->next=head;
         head->prev=newnode;
         head=newnode;
         return;
    }
    if (tmp->next == NULL) //tail hole
    {
        // valid index -> tail a insert hobe ; //tail update kora lage
        newnode->prev = tmp; // newnode->prev=tail;// --->> same
        tmp->next = newnode; // tail->next=newnode;
        tail = newnode;
        return;
    }
    newnode->next = tmp->next;
    tmp->next = newnode;
    newnode->prev = tmp;
    newnode->next->prev = newnode;
}
void print(Node *head)
{
    while (head != NULL)

    {
        cout << head->value << " ";
        head = head->next;
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
            break;
        input(head, tail, val);
    }
    // cout<<head->value<<" "<<tail->value<<endl;
    insert_at_position(head, tail, 0, 100);
    insert_head(head, tail, 20);
    // delete_tail(head,tail);
    // delete_position(head, tail, 0);
    print(head);
    return 0;
}