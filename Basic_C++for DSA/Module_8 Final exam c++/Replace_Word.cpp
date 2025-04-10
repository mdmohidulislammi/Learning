#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s,p;
        cin>>s>>p;
        while(s.find(p)!=-1)
        {
            s.replace(s.find(p),p.size(),"#");
        }
        cout<<s<<endl;
    }
    return 0;
}