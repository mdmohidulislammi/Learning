#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a="Hello";
    string b="World";
   a+=b; //a=a+b;//a.append(b);
    cout<<a<<endl;
    //a="helloa";->works
    //a=a+'A';->works;
    //a[5]='A';->not work;
   /* a.push_back('A');
    a.pop_back();
    a.pop_back();*/
    a.erase(5,1);  
    a.replace(4,0,"so");//a.insert (5,"world ju");
    cout<<a<<endl;
    return 0;
}