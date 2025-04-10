#include<bits/stdc++.h>
using namespace std;
class student
{
    public:
    int roll;
    int cls;
    float gpa;
    student(int roll, int cls, float gpa)
    {
        this->roll=roll;
        this->cls=cls;
        this->gpa=gpa;
    }
};
student *fun()
{
    student rahim(232, 5, 5.1);
    student *p=&rahim;
    return p;
}
int main()
{
    student* ans=fun();
    cout<< ans->roll<<" "<<ans->cls<<" "<<ans->gpa<<endl;
    return 0;
} 