#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v={1,2,3,5};
    //one value
    //v.erase(v.begin()+2);
    v.erase(v.begin()+1,v.end()-1);
    for(int c:v)
    {
        cout<<c<<" ";
    }
    return 0;
}