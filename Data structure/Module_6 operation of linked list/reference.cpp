#include<bits/stdc++.h>
using namespace std;
void fun(int *&p)
{
    *p=NULL;
    cout<<&p<<endl;
}
int main()
{
    int val=10;
    int* ptr=&val;
    fun(ptr);
    cout<<&ptr<<endl;
    cout<<&val<<endl;
    cout<<val<<endl;
    return 0;
}