#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int>mylist={10,20,30,40,50,10,20,30,50,40};
    //mylist.remove(10);
    //mylist.sort();
    //mylist.sort(greater<int>());
    //mylist.unique();//with sort
    mylist.reverse();
    for(int val: mylist)
    cout<<val<<" ";
    return 0;
}