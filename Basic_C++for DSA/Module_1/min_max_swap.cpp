#include<iostream>
#include<algorithm>
#include<utility>//for swap
/*void my_swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}*/
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    swap(a,b);
   //int mn=min(a,b);
   //int mx=max(a,b);
   cout<< a<<" "<<b;
  /* int mn=min({a,b,c,d});
   int mx=max({a,b,c,d});
   cout <<mn<<" "<<mx<<" ";*/
    return 0;
}