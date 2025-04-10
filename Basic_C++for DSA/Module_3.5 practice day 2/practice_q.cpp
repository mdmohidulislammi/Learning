#include<bits/stdc++.h>
using namespace std;
class Student
{
    public:
    char name[100];
    int cls;
    char sec;
    int roll;
    int marks;
    Student (const char* name, int cls, char sec, int roll, int marks)
    {
        strcpy(this->name,name);
        this->cls=cls;
        this->sec=sec;
        this->roll=roll;
        this->marks=marks;
    }
};
int main()
{
    char s[100],c[100],p[100],q,w,e;
    int ma,mar,mark,cl,cls,ls,r,ro,rol;
    cin.getline(s,100);    
    cin>>cl>>q>>r>>ma;   
    getchar(); cin.getline(c,100);     
     cin>>cls>>w>>ro>>mar;
     getchar();
    Student a(s,cl,q,r,ma),b(c,cls,w,ro,mar),d(p,ls,e,rol,mark);
    cout<<a.name<<" "<<a.cls<<" "<<a.sec<<" "<<a.roll<<" "<<a.marks<<endl
    <<b.name<<" "<<b.cls<<" "<<b.sec<<" "<<b.roll<<" "<<b.marks;
    return 0;
}