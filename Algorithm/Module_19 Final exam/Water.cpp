#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    for(int p=0;p<test;p++)
    {
        long long n;
        cin>>n;
        vector<long long> v;
        long long h1=INT_MIN,h2=INT_MIN,si,ei;
        for(int i=0;i<n;i++)
        {
            long long val;
            cin>>val;
            v.push_back(val);
            if(val>h1)
            {
                h1=val;
                si=i;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i==si) continue;
            else
            {
                if(v[i]>h2)
                {
                    h2=v[i];
                    ei=i;
                }
            }
        }
        if(si<ei) cout<<si<< " "<<ei<<endl;
        else cout<<ei<<" "<<si<<endl;

    }
    return 0;
}