#include<bits/stdc++.h>
using namespace std;
class student
{
    public:
    char name[100];
    int roll;
    float cgpa;
} ;
int main()
{
    student a,b;
    char tmp[100]={"Mohidul Islam"};
    strcpy(a.name,tmp);
    a.roll=1;
    a.cgpa=4;
    cout<<a.name<< " "<<a.roll<< " " <<a.cgpa;
  /*  cin.getline(a.name,sizeof(a.name));
    cin>>a.roll>>a.cgpa;
    getchar();
    cin.getline(b.name,sizeof(b.name));
    cin>>b.roll>>b.cgpa;
    cout<<a.name<<" " <<a.roll<<" " <<a.cgpa
    <<" " <<endl<<b.name<<" " <<b.roll<<" " <<b.cgpa;*/
    return 0;
}