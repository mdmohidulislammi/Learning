#include<bits/stdc++.h>
using namespace std;
class student 
{
    public:
    int cls;
    int roll;
    float gpa;
    student (int cls, int roll, float gpa)
    {
        this->cls=cls;
        this->roll=roll;
        this->gpa=gpa;
    }
};
student *fun()
{
    student*rahim=new student(32, 43, 4.44);
    return rahim;
}
int main()
{
    /*student *karim=new student(32, 32, 4.99);
    cout<<karim->cls<<" "<<karim->roll<< " "<<karim->gpa<<endl;*/
    student* ans =fun();
    cout<<ans->cls<< " "<<ans->roll<<" "<<ans->gpa<<endl;
    delete ans;
    cout<<ans->cls<<" "<<ans->roll<<" "<<ans->gpa<<endl;
    return 0;
}