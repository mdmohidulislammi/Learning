#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    list<int> mylist;
    for (int i = 0; i < q; i++)
    {
        int n, val;
        cin >> n >> val;
        if (n == 0)
        {
            mylist.push_front(val);
            cout << "L -> ";
            for (int value : mylist)
            {
                cout << value << " ";
            }
            cout << endl
                 << "R -> ";
            mylist.reverse();
            for (int value : mylist)
            {
                cout << value << " ";
            }
            mylist.reverse();
        }
        else if (n == 1)
        {
            mylist.push_back(val);
            cout << "L -> ";
            for (int value : mylist)
            {
                cout << value << " ";
            }
            cout << endl
                 << "R -> ";
            mylist.reverse();
            for (int value : mylist)
            {
                cout << value << " ";
            }
            mylist.reverse();
        }
        else if (n == 2)
        {
            if(mylist.size()>val)
            {
                mylist.erase(next(mylist.begin(), val));
            }
            cout << "L -> ";
            for (int value : mylist)
            {
                cout << value << " ";
            }
            cout << endl
                 << "R -> ";
            mylist.reverse();
            for (int value : mylist)
            {
                cout << value << " ";
            }
            mylist.reverse();
        }
        cout<<endl;
    }
    return 0;
}