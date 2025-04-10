#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v={1,3,4,2,3,4,2,2,4,5,2};
   /* vector<int>::iterator it;
    it =find(v.begin(),v.end(),3);
    cout<<*it;    */
    auto it=find(v.begin(),v.end(),3);
    if(it==v.end()) cout<<"NOT FOUND";
    else cout<<"Found";
    return 0;
}