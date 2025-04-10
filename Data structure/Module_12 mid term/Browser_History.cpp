#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    string st;
    Node *next;
    Node *prev;
    Node(string st)
    {
        this->st = st;
        this->next = NULL;
        this->prev = NULL;
    }
};
void input_linked(Node *&head, Node *&tail, string st)
{
    Node *newnode = new Node(st);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    while (true)
    {
        string st;
        cin >> st;
        if (st == "end")
            break;
        input_linked(head, tail, st);
    }
    Node *current = head;
    int q;
    cin >> q;
    getchar();
    for (int i = 0; i < q; i++)
    {        
        string cmd;
        getline(cin, cmd);
        stringstream ss(cmd);
        string address,operation;
        ss>>operation;        
            if (operation=="visit")
            {
                Node* tmp=head;
                ss>>address;
                while (tmp != NULL)
                {
                    if(tmp->st==address)
                    {
                        break;
                    }
                    tmp = tmp->next;                   
                }
                if (tmp == NULL)
                {
                    cout << "Not Available";
                }
                else if (address == tmp->st)
                {
                    cout << tmp->st;
                    current = tmp;
                }
                else if (address!= tmp->st)
                    cout << "Not Available";
            }
        //tmp = current;
        if (operation == "next")
        {
            if (current->next != NULL )
            {
                cout << current->next->st;
                current = current->next;                
            }
            else
            {
                cout << "Not Available";
            }
        }
        else if (operation == "prev")
        {
            if (current->prev != NULL )
            {
                cout << current->prev->st;
                current = current->prev;
            }
            else
            {
                 cout << "Not Available";
            }
        }
        if(i<q-1)
        cout<<endl;
    }
    return 0;
}