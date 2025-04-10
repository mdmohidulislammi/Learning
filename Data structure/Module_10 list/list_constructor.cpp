#include<bits/stdc++.h>
using namespace std;
int main()
{
    //list<int>myllist;
    //int a[5]={10,20 ,30 ,50, 40};
    //vector<int>v(5,5);
    //vector<int>v={10,40,10,50,50};
    list<int>my={10,20,50,50,30};
   // list<int>mylist(5,5);
   list<int>mylist(my);
  /// list<int>mylist(v.begin(),v.end());
  // list<int>mylist(a,a+5);
    cout<<mylist.size()<<endl;
    //list<int>::iterator it;
    for(list<int>::iterator it =mylist.begin();it!=mylist.end();it++)//auto it
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    for(int c: mylist)
    {
        cout<<c<<" ";
    }
    return 0;
}