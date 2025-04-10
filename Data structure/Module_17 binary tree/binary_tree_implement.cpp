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
void preOrder(Node* root)
{
  if(root==NULL)//base case
  return;
  cout<<root->value<<" ";
  preOrder(root->left);
  preOrder(root->right);
}
void postOrder(Node*root)
{
  if(root==NULL)//base case
  return;
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->value<<" ";
}
void inOrder(Node* root)
{
  if(root==NULL) return;
  inOrder(root->left);
  cout<<root->value<<" ";
  inOrder(root->right);
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
    root->right=b;
    root->left=a;
    a->left=e;
    a->right=f;
    e->right=g;
    f->left=h;
    b->left=c;
    b->right=d;
    c->left=i;
    d->left=j;
    //call recursion
    //preOrder(root);
    postOrder(root);
    cout<<endl;
    inOrder(root);
    return 0;
}