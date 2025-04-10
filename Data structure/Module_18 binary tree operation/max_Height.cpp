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
Node* input_binary()
{
    int value;
    cin>>value;
    Node* root;
    if(value==-1) root=NULL;
    else root=new Node(value);
    queue<Node*>q;
    if(root) q.push(root);
    while(!q.empty())
    {
        Node* p= q.front();
        q.pop();
        //2. All work 
        int l,r;
        cin>>l>>r;
        Node* myLeft;
        Node* myRight;
        if(l==-1) myLeft=NULL;
        else myLeft=new Node(l);
        if(r==-1) myRight=NULL;
        else myRight=new Node(r);
        p->left=myLeft;
        p->right=myRight;
        //3. Children Node
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right); 
    }
    return root;
}
int count_height(Node* root)
{
    if(root==NULL) return 0;
    int l=count_height(root->left);
    int r=count_height(root->right);
    return max(l,r)+1;
}
int main()
{
    Node* root=input_binary();
    cout<<count_height(root)<<endl;
    return 0;
}