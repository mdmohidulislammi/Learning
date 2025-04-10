#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<v.size();i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int target;
        bool flag=false;
        cin>>target;
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(v[mid]==target)
            {
                flag=true;
            }
            else if(target<v[mid])
            r=mid-1;
            else
            l=mid+1;
        }
        if(flag==true) cout<<"YES";
        else cout<<"NO";
    }
    return 0;
}