#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v={1,3,3,5,3};
    vector<int>v1={100 ,010,10};
    v.insert(v.begin()+2,v1.begin(),v1.end());//for one value v.insert(v.begin()+1,10);
    for(int n:v)
    {
        cout<<n<<" ";
    }
    return 0;
}