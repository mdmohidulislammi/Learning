#include<bits/stdc++.h>
using namespace std;
void chocolate(int packets,int total)
{
     if(packets<3) 
     {
        cout<<total<<endl;
        return ;
     }
     int number=packets/3;
     total+=number;
     packets=number +(packets-(number*3));
     chocolate(packets,total);
}
int main()
{
    int test ;
    cin>>test;
    for(int i=0;i<test;i++)
    {
         int taka;
         cin>>taka;
         int get=taka/5;
         chocolate(get,get);         
    }
    return 0;
}