#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int num;
    Node* next;
    Node(int num)
    {
        this->num=num;
        this->next=NULL;
    }
};
int main()
{
    Node a(10),b(20),c(30);
    a.next=&b;
    b.next=&c;
    cout<<a.next->num<<endl;
    cout<<a.num<<endl;
    cout<<b.next->num<<endl;
    return 0;
}