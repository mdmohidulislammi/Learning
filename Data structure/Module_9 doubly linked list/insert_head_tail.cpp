#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insert_at_position(Node *head, int pos, int value)
{
    Node *tmp = head;
    Node *newnode = new Node(value);
    for (int i = 1; i < pos; i++)
    {
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    tmp->next = newnode;
    newnode->prev = tmp;
    newnode->next->prev = newnode;
}
void insert_head(Node *&head, Node *&tail, int value)
{
    Node *newnode = new Node(value);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
void insert_tail(Node *&head, Node *&tail, int value)
{
    Node *newnode = new Node(value);
    if (tail == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
void print(Node *head, Node *tail)
{
    Node *tmp = head;
    Node *tmp1 = tail;
    while (tmp != NULL)
    {

        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
    while (tmp1 != NULL)
    {
        cout << tmp1->value << " ";
        tmp1 = tmp1->prev;
    }
}
int size(Node *head)
{
    int cnt = 0;
    Node *tmp = head;
    while (tmp != NULL)
    {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *tail = c;
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    int pos, val;
    cin >> pos >> val;
    int cnt = size(head);
    if (pos == 0)
    {
        insert_head(head, tail, val);
    }
    else if (pos == cnt)
    {
        insert_tail(head, tail, val);
    }
    else if (pos >= cnt)
    {
        cout << "invalid" << endl;
    }
    else
    {
        insert_at_position(head, pos, val);
    }
    print(head, tail);
    return 0;
}