#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int>mylist ={10,20,30,40,50,60};
     //mylist.clear();
    cout<<mylist.size()<<endl;
    cout<<mylist.max_size()<<endl;
//    mylist.resize(2);
//    mylist.resize(10);
   mylist.remove(10);
    for(int val:mylist)
    {
        cout<<val<<" ";
    }
    return 0;
}