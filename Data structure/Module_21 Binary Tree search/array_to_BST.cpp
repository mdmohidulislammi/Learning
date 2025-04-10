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
Node *convert(int a[], int l, int r)
{
    if(l>r) return NULL;
    int mid = (l + r) / 2;
    Node *root = new Node(a[mid]);
    Node *rootLeft = convert(a, l, mid - 1);
    Node *rootRight = convert(a, mid + 1, r);
    root->left = rootLeft;
    root->right = rootRight;
    return root;
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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Node *root = convert(a, 0, n - 1);
    output(root);
    return 0;
}