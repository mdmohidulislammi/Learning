#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
          int value;
          Node* right;
          Node* left;
          Node(int value)
          {
            this->value=value;
            this->left=NULL;
            this->right=NULL;
          }
};
// void preOrder(Node* root)
// {
//     if(root==NULL) return;
//     cout<<root->value<<" ";
//     preOrder(root->left);
//     preOrder(root->right);
// }
void level_Order(Node* root)
{
    queue<Node*>q;
    q.push(root);
    while(! q.empty())
    {
        //1. Ber kore ana.
        Node* f=q.front();
        q.pop();
        //2. Work 
        cout<<f->value<<" ";
        //3. Go to next level
        if(f->left!=NULL) q.push(f->left);
        if(f->right!=NULL) q.push(f->right);
    }
}
int main()
{
    Node* root=new Node(10);
    Node* a=new Node(20);
    Node* b=new Node(30);
    Node* c=new Node(40);
    Node* d=new Node(50);
    Node* e=new Node(60);
    Node* f=new Node(70);
    Node* g=new Node(80);
    Node* h=new Node(90);
    Node* i=new Node(100);
    Node* j=new Node(110);
    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->left=e;
    b->right=f;
    c->right=g;
    d->left=h;
    e->right=i;
    f->left=j;
    level_Order(root);
    return 0;
}