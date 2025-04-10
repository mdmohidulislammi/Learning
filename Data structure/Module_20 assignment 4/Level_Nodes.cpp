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
int max_height(Node* root)
{
    if(root == NULL) return 0;
    if(root->left==NULL && root->right==NULL)
    return 1;
    int l=max_height(root->left);
    int r=max_height(root->right);
    return max(l,r)+1;
}
void level_print(Node* root, int x)
{
    queue<pair<Node* ,int> >q;
    if(root) q.push({root,0});
    while(!q.empty())
    {
        pair<Node*,int> p=q.front();
        Node* node=p.first;
        int level=p.second;
        q.pop();

        if(level==x)
        cout<<node->value<<" ";

        if(node->left) q.push({node->left,level+1});
        if(node->right) q.push({node->right, level+1});
    }
}
int main()
{
    Node* root=input();
    int x;
    cin>>x;
    int h=max_height(root);
    if(x<h)
    {
        level_print(root, x);
    }
    else cout<<"Invalid";
    return 0;
}