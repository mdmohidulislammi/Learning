#include<bits/stdc++.h>
using namespace std;
class student
{
    public:
    int uid;
    char name[100];
    char sec;
    int mark;
    student (int uid,const char* name ,char sec, int mark)
    {
        this->uid=uid;
        strcpy(this->name,name);
        this->sec=sec;
        this->mark=mark;
    }
};
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int d,f,g,ma,mar,mrk;
        char nam[100],n[100],am[100],sc,s,e;
        cin>>d>>nam>>sc>>ma
        >>f>>n>>s>>mar>>g>>am>>e>>mrk;
        student a(d,nam,sc,ma),b(f,n,s,mar),c(g,am,e,mrk);
        if(a.mark>=b.mark && a.mark>=c.mark)
        {
            if(a.mark ==b.mark)
            {
                if(a.uid<b.uid)
                cout<<a.uid<< " "<<a.name<<" "<<a.sec<<" "<<a.mark<<endl;
                else
                cout<<b.uid<< " "<<b.name<<" "<<b.sec<<" "<<b.mark<<endl;
            }
            else if(a.mark==c.mark)
            {
                if(a.uid<c.uid)
                cout<<a.uid<< " "<<a.name<<" "<<a.sec<<" "<<a.mark<<endl;
                else
                cout<<c.uid<< " "<<c.name<<" "<<c.sec<<" "<<c.mark<<endl;
            }
            else
            cout<<a.uid<< " "<<a.name<<" "<<a.sec<<" "<<a.mark<<endl;            
        } 
       else if(b.mark>=a.mark && b.mark>=c.mark)
        {
            if(b.mark ==a.mark)
            {
                if(b.uid<a.uid)
                cout<<b.uid<< " "<<b.name<<" "<<b.sec<<" "<<b.mark<<endl;
                else
                cout<<a.uid<< " "<<a.name<<" "<<a.sec<<" "<<a.mark<<endl;
            }
            else if(b.mark==c.mark)
            {
                if(b.uid<c.uid)
                cout<<b.uid<< " "<<b.name<<" "<<b.sec<<" "<<b.mark<<endl;
                else
                cout<<c.uid<< " "<<c.name<<" "<<c.sec<<" "<<c.mark<<endl;
            }
            else
           cout<<b.uid<< " "<<b.name<<" "<<b.sec<<" "<<b.mark<<endl;         
        }   
       else
        {
           if(c.mark ==a.mark)
           {
            if(a.uid<c.uid)
                cout<<a.uid<< " "<<a.name<<" "<<a.sec<<" "<<a.mark<<endl;
                else
                cout<<c.uid<< " "<<c.name<<" "<<c.sec<<" "<<c.mark<<endl;
                
            }
            else if(b.mark==c.mark)
            {
                if(b.uid<c.uid)
                cout<<b.uid<< " "<<b.name<<" "<<b.sec<<" "<<b.mark<<endl;
                else
                cout<<c.uid<< " "<<c.name<<" "<<c.sec<<" "<<c.mark<<endl;
            }
            else
             cout<<c.uid<< " "<<c.name<<" "<<c.sec<<" "<<c.mark<<endl;
        }
       }
       return 0;      
    }