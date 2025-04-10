#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    priority_queue<int> pq;
    while (test--)
    {
        int option, val;
        cin >> option;
        if (option == 1)
        {
            cin >> val;
            pq.push(val);
        }
        else
        {
            if (!pq.empty())
            {
                cout << pq.top();
                pq.pop();
            }
            else
                cout << "empty";
                cout<<endl;
        }
    }
    return 0;
}