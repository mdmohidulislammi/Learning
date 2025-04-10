#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int num;
    Node* next;
    // Node(int num)
    // {
    //     this->num=num;
    //     this->next=NULL;
    // }
};
int main()
{
    Node a,b;
    a.num=10;
    b.num=20;
    a.next=&b;
    b.next=NULL;
    cout<<a.num<<endl;
    cout<<b.num<<endl;
    cout<<a.next->num<<endl;   
    return 0;
}