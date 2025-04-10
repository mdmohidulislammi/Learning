#include<bits/stdc++.h>
using namespace std;
class person
{
    public:
    string name;
    int age;
    person(string name, int age)
    {
        this->age=age;
        this->name=name;
    }
};
int main()
{
    person* rakib=new person("Rakib",34);
    person* sakib=new person("Sakib",23);
    *rakib=*sakib;
     delete sakib;
     cout<<rakib->age<<" "<<rakib->name<<endl;
    return 0;
}