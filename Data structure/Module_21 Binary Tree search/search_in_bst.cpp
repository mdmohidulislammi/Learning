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
bool search(Node *root, int val)
{
    if (root == NULL)
        return false;
    if (root->value == val)
        return true;
    if (root->value > val)
        return search(root->left, val);
    else
        return search(root->right, val);
}
int main()
{
    Node *root = input();    
    int n;
    cin>>n;
    bool find = search(root, n);
    if (find == true)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}