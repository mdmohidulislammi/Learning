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
Node *convert(long long a[],int l, int r)
{
    if (l > r)
        return NULL;
    int mid=(l+r)/2;

    Node* root = new Node(a[mid]);
    Node *rootL = convert(a, l, mid - 1);
    Node *rootR = convert(a, mid+ 1, r);
    root->left = rootL;
    root->right = rootR;
    return root;
}
void print_level(Node *root)
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

        if (parent->left)
            q.push(parent->left);
        if (parent->right)
            q.push(parent->right);
    }
}
int main()
{
    int n;
    cin >> n;
    long long m = pow(2, n) - 1;
    // cout << m;
    long long a[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    Node *root;
    for (int i = 0; i < m; i++)
    {
        if (a[i] == 1)
        {

            root = convert(a, 0, m - 1);
            break;
        }
    }
    print_level(root);
    return 0;
}