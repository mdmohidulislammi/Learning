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
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *pr = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *myLeft;
        Node *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);
        if (myLeft)
            pr->left = myLeft;
        if (myRight)
            pr->right = myRight;

        if (pr->left)
            q.push(pr->left);
        if (pr->right)
            q.push(pr->right);
    }
    return root;
}
int sum = 0;
void sum_without_Leaf(Node *root)
{
    if (root == NULL)
        return;
    if (root->left != NULL || root->right != NULL)
        sum += root->value;
    sum_without_Leaf(root->left);
    sum_without_Leaf(root->right);
}
// void output(Node *root)
// {
//     if (root == NULL)
//         return;
//     queue<Node *> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         Node *p = q.front();
//         q.pop();
//         cout << p->value << " ";
//        if(p->left!=NULL) q.push(p->left);
//        if(p->right!=NULL) q.push(p->right);
//     }
// }
int main()
{
    Node *root = input_fun();
    sum = 0;
    sum_without_Leaf(root);
    cout << sum;

    return 0;
}