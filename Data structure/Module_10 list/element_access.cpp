#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int>mylist={10,30,20,40,50,60};
    cout<<mylist.front()<<endl;
    cout<<mylist.back()<<endl;
    cout<<*next(mylist.begin(),3);
    return 0;
}