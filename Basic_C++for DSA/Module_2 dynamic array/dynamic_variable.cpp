#include<bits/stdc++.h>
using namespace std;
int *fun() //int** fun()
{
    int *a=new int;
    *a=10;
    cout<<"fun " <<a <<endl;
    return a;
}
int main()
{
    int *p=fun();
    cout <<"main "<<*p<<endl;
   /* //int x=10;
    int **p=fun();
    cout<<"main "<<p<<endl;//
  /*  cout<<*a<<endl;//deference
    float*b=new float;
    *b=108.484;
    cout<<fixed<<setprecision(2)<<*b;*/
    return 0;
}