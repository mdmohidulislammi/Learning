#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int a,b,c,p=0;
    cin>>a>>b;
    replace(v.begin(),v.end(),a,b);
    cin>>c;
    // vector<int>::iterator it;
    // it=find(v.begin(),v.end(),c);
    // for(int c:v)
    // {cout<<c<<" ";}    
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
        if(c==v[i])
        {
            if(p==0)
            p=i;
        }       
    }
    cout<<endl;
    if(p==0)
    cout<<"-1";
    else{cout<<p;}
    return 0;
}