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
void insert(Node *&root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return;
    }
    if (val < root->value)
    {
        if (root->left == NULL)
            root->left = new Node(val);
        else
            insert(root->left, val);
    }
    else if (val > root->value)
    {
        if (root->right == NULL)
            root->right = new Node(val);
        else
            insert(root->right, val);
    }
}
void output(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        cout << p->value << " ";

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
}
int main()
{
    Node *root = input();
    insert(root, 12);
    insert(root, 13);
    insert(root, 11);
    insert(root, 40);
    insert(root, 32);
    output(root);
    return 0;
}