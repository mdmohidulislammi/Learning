#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int>mylist={10,20,30,40,50};
    list<int>newlist={60,70,80,90};
  //   //assign 
  //   list<int>mylist2={10,200,10,40,50,30,50,40,60};
  //   list<int>mylist;
  //  // mylist=mylist2;
  //   mylist.assign(mylist2.begin(),mylist2.end());
  //     mylist.push_back(10);
    //   mylist.push_front(200);
      // mylist.pop_back();
      // mylist.pop_front();

      //insert
     // mylist.insert(next(mylist.begin(),4),100);
    // mylist.insert(next(mylist.begin(),2),{10,20,30});
    //mylist.insert(next(mylist.begin(),5),newlist.begin(),newlist.end());
    //erase
    mylist.erase(next(mylist.begin(),3));
   // mylist.erase(next(mylist.begin(),2),next(mylist.begin(),4));
    //  auto it=find(mylist.begin(),mylist.end(),1000);
    //  if(it==mylist.end())cout<<"Not found"<<endl;
    // else cout<<"found"<<endl;
    //replace(mylist.begin(),mylist.end(),30,100);
    for(int val: mylist)
    cout<<val<<" ";
    return 0;
}