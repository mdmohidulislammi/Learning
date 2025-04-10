#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<string>ls;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        ls.push_back(s);
    }
   for(int i=0;i<n;i++)
   {
    cout<<ls.front()<<endl;
   }
    return 0;
}