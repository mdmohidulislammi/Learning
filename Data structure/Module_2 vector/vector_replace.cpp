#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v={1,3,3,5,45,2,1,2,2,2,10};
    replace(v.begin(),v.end(),2,13);
    for(int c:v)
    cout<<c<<" ";
    return 0;
}