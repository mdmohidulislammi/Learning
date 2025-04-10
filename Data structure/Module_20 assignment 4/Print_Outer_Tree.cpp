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
Node *input()
{
    Node *root;
    int val;
    cin >> val;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *parent = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *inL, *inR;
        if (l == -1)
            inL = NULL;
        else
            inL = new Node(l);
        if (r == -1)
            inR = NULL;
        else
            inR = new Node(r);

        if (inL)
            parent->left = inL;
        if (inR)
            parent->right = inR;

        if (parent->left)
            q.push(parent->left);
        if (parent->right)
            q.push(parent->right);
    }
    return root;
}
void outer(Node* root)
{
   // if(root==NULL) return;
    if(root->left)
    {
        outer(root->left);
        cout<<root->value<<" ";
    }
    else if(root->right)
    {
        outer(root->right);
        cout<<root->value<<" ";
    }
    if(root->left==NULL && root->right==NULL)
    cout<<root->value<<" ";
}
void outer_right(Node* root)
{
   /// if(root==NULL) return;
    if(root->right)
    {
        cout<<root->right->value<<" ";
        outer_right(root->right);
    }
    else if(root->left)
    {
        cout<<root->left->value<<" ";
        outer_right(root->left);
    }
}
// void outer_only_right(Node* root)
// {
//     if(root==NULL) return;
//     if(root->right)
//     {
//         outer_only_right(root->right);
//         cout<<root->value<<" ";
//     }
//     else if(root->left)
//     {
//         outer_only_right(root->left);
//         cout<<root->value<<" ";
//     }
//     if(root->left==NULL && root->right==NULL)
//     cout<<root->value<<" ";
// }
int main()
{
    Node* root =input();
    if(root->left && root->right)
    {
        outer(root);
        outer_right(root);
    }
    else if(root->left && root->right==NULL)
    {
        outer(root);
    }
    else 
    {
        cout<<root->value<<" ";
        outer_right(root);
    }
    return 0;
}