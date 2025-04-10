#include<bits/stdc++.h>
using namespace std;
class person
{
    public:
    string name;
    int age;
    person(string name, int age)
    {
        (*this).age=age;
        (*this).name=name;
    }
};
int main()
{
    person rakib("rakib",24);
    cout<<rakib.age<<" "<<rakib.name<<endl;
    return 0;
}