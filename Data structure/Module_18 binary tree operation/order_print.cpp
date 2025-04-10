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
Node* input()
{
    Node* root;
    int val;
    cin>>val;
    if(val==-1) root=NULL;
    else root=new Node(val);
    queue<Node*> q;
    if(root) q.push(root);
    while(!q.empty())
    {
        Node* parent=q.front();
        q.pop();
        int inLeft,inRight;
        cin>>inLeft>>inRight;
        Node* newL,*newR;
        if(inLeft==-1) newL=NULL;
        else newL=new Node(inLeft);
        if(inRight==-1) newR=NULL;
        else newR=new Node(inRight);

        parent->left=newL;
        parent->right=newR;
        
        if(parent->left) q.push(parent->left);
        if(parent->right) q.push(parent->right);
     }
    return root;
}
void print(Node* root)
{
    if(root==NULL) return ;
    cout<<root->value<<" ";
    print(root->left);
    print(root->right);
    
}
int main()
{
    Node* root=input();
    print(root);
    return 0;
}