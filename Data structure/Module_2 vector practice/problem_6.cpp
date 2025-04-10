#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<string>v(n);
    for(int i=0;i<v.size();i++)
    {
        cin>>v[i];
        //cin.ignore(); Enter e no problem
    }
    for(string ss:v)
    {
        int q=(int)ss[0]-32;
        ss[0]=(char)q;
        cout<<ss<<endl;
    }
    return 0;
}