#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int >v;
    v.push_back(10);
    v.push_back(20);
    cout<<v.size()<<endl;
    v.push_back(30);
    v.push_back(40);
   // cout<<v.size()<<endl;
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);
    v.push_back(80);
    v.push_back(90);
    v.clear();
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<v[3];
    return 0;
}