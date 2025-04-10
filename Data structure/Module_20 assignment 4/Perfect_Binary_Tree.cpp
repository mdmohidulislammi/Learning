#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->value = value;
        left = NULL;
        right = NULL;
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
int cnt=0;
void count_node(Node* root)
{
    if(root==NULL) return ;
    cnt++;
    count_node(root->left);
    count_node(root->right);
}
int main()
{
    Node* root=input();
    cnt=0;
    count_node(root);
    int h=max_height(root);
    if(pow(2,h)-1 == cnt)
    cout<<"YES";
    else cout<<"NO";
    return 0;
}