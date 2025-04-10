#include <bits/stdc++.h>
using namespace std;
void insert_in_min(vector<int> &v, int val)
{
    v.push_back(val);
    int current = v.size() - 1;
    while (current != 0)
    {
        int parent = (current - 1) / 2;
        if (v[parent] > v[current])
            swap(v[parent], v[current]);
        else
            break;
        current = parent;
    }
}
void delete_heap(vector<int> &v)
{
    v[0] = v[v.size() - 1];
    v.pop_back();
    int current = 0;
    while (true)
    {
        int left = (current * 2) + 1;
        int right = (current * 2) + 2;
        int last = v.size();
        if (left < last && right < last)
        {
            if (v[left] <= v[right] && v[left] < v[current])
            {
                swap(v[left], v[current]);
                current = left;
            }
            else if (v[right] <= v[left] && v[right] < v[current])
            {
                swap(v[right], v[current]);
                current = right;
            }
            else
                break;
        }
        else if (left < last)
        {
            if (v[left] < v[current])
            {
                swap(v[left], v[current]);
                current = left;
            }
            else
                break;
        }
        else if (right < last)
        {
            if (v[right] < v[current])
            {
                swap(v[right], v[current]);
                current = right;
            }
            else
                break;
        }
        else
            break;
    }
}
void print_fun(vector<int> v)
{
    if (v.empty())
        cout << "Empty" << endl;
    else
        cout << v[0] << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insert_in_min(v, val);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int com;
        cin >> com;
        if (com == 0)
        {
            int value;
            cin >> value;
            insert_in_min(v, value);
            print_fun(v);
        }
        else if (com == 1)
        {
            print_fun(v);
        }
        else
        {
            if(!v.empty())
            delete_heap(v);
            print_fun(v);
        }
    }
    return 0;
}