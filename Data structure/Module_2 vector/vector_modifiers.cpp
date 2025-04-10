#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>x={1 , 2 ,3};
    vector<int> v={1,3,4};
    v=x;//x and v er elements shoman hole O(1) otherwise x er element O(N);
    v.push_back(10);
  //  v.pop_back();
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}