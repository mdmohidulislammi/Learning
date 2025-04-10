#include<bits/stdc++.h>
using namespace std;
int main()
{
    //type 1 
   // vector<int>v;
  // type 2
  //vector<int>v(5);
  //type 3
  //vector<int>v(5,10);
  //type 4
  /*vector<int>v1(4,10);
  vector<int>v(v1);*/
  /*type 5
  int a[5]={1,33 ,44,4,5};
  vector<int>v(a,a+5);*/
  /*type 6*/
  vector <int>v={3, 4 ,4};
  v.resize(2);
  v.resize(5);
  for(int i=0;i<v.size();i++)
  {
    cout<<v[i]<<" ";
  }
    cout<<endl<<v.size();
    return 0;
}