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
Node* input_binary()
{
    int value;
    cin>>value;
    Node* root;
    if(value==-1) root=NULL;
    else root=new Node(value);
    queue<Node*>q;
    if(root) q.push(root);
    while(!q.empty())
    {
        Node* p= q.front();
        q.pop();
        //2. All work 
        int l,r;
        cin>>l>>r;
        Node* myLeft;
        Node* myRight;
        if(l==-1) myLeft=NULL;
        else myLeft=new Node(l);
        if(r==-1) myRight=NULL;
        else myRight=new Node(r);
        p->left=myLeft;
        p->right=myRight;
        //3. Children Node
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right); 
    }
    return root;
}
void level_Order(Node* root)
{
    if(root==NULL) 
    {
        cout<<"Root nai";
        return;
    }
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
    Node* root=input_binary();
    level_Order(root);
    return 0;
}