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
void print_fun(vector<int>v)
{
    if(v.empty()) cout<<"Empty"<<endl;
    else 
    for(int val:v)
    cout<<val<<" ";
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insert_in_min(v, val);
    }
    delete_heap(v);
    delete_heap(v);
    delete_heap(v);
    delete_heap(v);
    delete_heap(v);
    delete_heap(v);
    delete_heap(v);
    delete_heap(v);
    //delete_heap(v);
    //delete_heap(v);
    print_fun(v);
    return 0;
}