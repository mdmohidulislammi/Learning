#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *right;
    Node *left;
    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};
void Pre_order(Node *root)
{
    if(root==NULL) return;
    cout << root->value << " ";
    Pre_order(root->left);
    Pre_order(root->right);
}
void Post_order(Node* root)
{
    if(root==NULL) return;
    Post_order(root->left);
    Post_order(root->right);
    cout << root->value << " ";
}
void in_Order(Node* root)
{
    if(root==NULL) return;
    in_Order(root->left);
    cout << root->value << " ";
    in_Order(root->right);
}
int main()
{
    Node *root = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);
    Node *f = new Node(70);
    Node *g = new Node(80);           // Note book 
    Node *h = new Node(90);
    Node *i = new Node(100);
    Node *j = new Node(110);
    Node *k = new Node(120);
    Node *l = new Node(130);
    Node *m = new Node(140);
    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->left=e;
    b->right=f;
    c->left=g;
    d->right=h;
    e->left=i;
    f->left=j;
    f->right=k;
    k->left=l;
    k->right=m;
    Pre_order(root);
    cout<<endl;
    Post_order(root);
    cout<<endl;
    in_Order(root);
    return 0;
}