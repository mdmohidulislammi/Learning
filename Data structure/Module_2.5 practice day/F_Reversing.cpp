#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<v.size();i++) 
    {
        cin>>v[i];
    }  
    reverse(v.begin(),v.end());
    // int j=v.size()-1;
    // for(int i=0;i<j;i++)
    // {
    //     swap(v[i],v[j]);
    //     j--;
    // }
    for(int c:v)
    cout<<c<<" ";
    return 0;
}