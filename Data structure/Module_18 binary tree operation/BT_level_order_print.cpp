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
    q.push(root);
    while (!q.empty())
    {
        Node *parent = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *leftIn, *rightIn;
        if (l == -1)
            leftIn = NULL;
        else
            leftIn = new Node(l);
        if (r == -1)
            rightIn = NULL;
        else
            rightIn = new Node(r);
        parent->left = leftIn;
        parent->right = rightIn;
        if (parent->right)
            q.push(parent->right);
        if (parent->left)
            q.push(parent->left);
        // if(parent->right)q.push(parent->right);
    }
    return root;
}
void print(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *parent = q.front();
        q.pop();
        cout << parent->value << " ";
        // if(parent->right) q.push(parent->right);
        if (parent->left)
            q.push(parent->left);
        if (parent->right)
            q.push(parent->right);
    }
}
int node_count(Node *root)
{
   if(root==NULL) return 0;// ekta children thakle tokhon null e chole jay left e ba right e , ejonno ei base case ta must dite hobe .
    if (root->left == NULL && root->right == NULL)
        return root->value;
    int l = node_count(root->left);
    int r = node_count(root->right);
    return l + r + root->value;
}
int main()
{
    Node *root = input();
    // print(root);
    cout << node_count(root);
    return 0;
}