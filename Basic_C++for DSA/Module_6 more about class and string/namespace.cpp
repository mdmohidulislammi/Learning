#include<bits/stdc++.h>
using namespace std;
namespace rakib
{
    int age=25;
    void hello()
    {
        cout<<"Rakib namespace"<<endl;
    }

}
namespace sakib
{
    int age2=23;
    void hello()
    {
        cout<<"sakib namespae"<<endl;
    }
}
using namespace rakib;
int main()
{
    cout<<age<<endl;
    hello();
    sakib::hello();
}