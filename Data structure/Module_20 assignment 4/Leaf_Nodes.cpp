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
Node *input_fun()
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
vector<int> v;
void LeafNode(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        v.push_back(root->value);
    LeafNode(root->left);
    LeafNode(root->right);
}
int main()
{
    Node *root = input_fun();
    v.clear();
    LeafNode(root);
    sort(v.begin(), v.end(), greater<int>());
    for (int value : v)
        cout << value << " ";
    return 0;
}