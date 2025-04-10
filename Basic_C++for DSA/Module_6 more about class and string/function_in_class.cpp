#include<bits/stdc++.h>
using namespace std;
class person
{
    public:
    string name;
    int age;
    int marks;
    person(string nm, int ag, int marks)
    {
        name = nm;
        age =ag;
        this->marks=marks;
    }    
    void hello()
    {
        cout<<name<<" "<<age<<marks<<endl;
    }
    int sum()
    {
        return marks+age;
    }
};

int main()
{
    person rakib("Rakib Ahsan",25,30);
    cout<<rakib.sum();
    return 0;
}