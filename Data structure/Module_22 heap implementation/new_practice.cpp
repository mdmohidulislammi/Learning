#include<bits/stdc++.h>
using namespace std;
void insert_heap(vector<int>&v, int val)
{
    v.push_back(val);
    int cur_in=v.size()-1;
    while(cur_in!=0)
    {
        int parent_index=(cur_in-1)/2;
        if(v[parent_index]< v[cur_in])
        {
            swap(v[parent_index],v[cur_in]);
            cur_in=parent_index;
        }
        else break;
        // cur_in=parent_index;
    }
}
void delete_heap(vector<int>&v)
{
    v[0]=v[v.size()-1];
    v.pop_back();
    int cur=0;
    while(true)
    {
        int valid=v.size();
        int left=(cur*2)+1;
        int right=(cur*2)+2;
        if(left<valid && right<valid)
        {
            if(v[left]>=v[right] && v[left]> v[cur])
            {
                swap(v[left],v[cur]);
                cur=left;
            }
            else if(v[right]>= v[left] && v[right]> v[cur])
            {
                swap(v[right],v[cur]);
                cur=right;
            }
            else break;
        }
        else if(left<valid)
        {
             if(v[left]> v[cur])
             {
                swap(v[left],v[cur]);
                cur=left;
             }
             else break;
        }
        else if(right<valid)
        {
            if(v[right]> v[cur])
            {
                swap(v[right],v[cur]);
                cur=right;
            }
            else break;
        }
        else break;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> v;    
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        insert_heap(v,val);
    }
    // delete_heap(v);
    // delete_heap(v);
    // delete_heap(v);
    // delete_heap(v);
    for(int val: v)cout<<val<<" ";
    return 0;
}