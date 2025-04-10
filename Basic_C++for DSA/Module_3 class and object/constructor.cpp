#include<bits/stdc++.h>
using namespace std;
class Student
{
    public:
    int roll ;
    int cls;
    float gpa;
    Student(int roll,int cls,float gpa)//(int r,int c,float g)->dile dereference kora lage na
    {
        (*this).roll=roll;//same to this->roll=roll
        (*this).cls=cls;
        (*this).gpa=gpa;
    }
};
int main()
{
    Student rahim(29, 9, 5.34);
    Student karim(1, 3, 5.54);
    cout<<rahim.roll<<" "<< rahim.cls<<" "<<rahim.gpa<<endl<<
    karim.roll<<" "<<karim.cls<<" "<<karim.gpa;
    return 0;
}
