#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    vector<string>v(n);
    for(int i=0;i<n;i++)
    {
        getline(cin,v[i]);
       /* string s;
        getline(cin,s);
        v[i]=s;*/
    }
  //This part for no getline//  
    // vector<string>v(n);//vector<string>v; hole push back;
    // for(int i=0;i<n;i++)
    // {
    //     // string s;
    //     // cin>>s;
    //     // //v.push_back(s);
    //    // v[i]=s;
    //    cin>>v[i];
    // }
    for(string ss:v)
    {
        cout<<ss<<endl;
    }
    return 0;
}