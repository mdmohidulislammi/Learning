#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin>>q;
    vector<int>v;
    for(int i=0;i<q;i++)
    {
        int value,option;
        cin>>option>>value;
        if(option==1)
        {
            if(v.size()<2)
            v.push_back(value);
            else
            for(int j=v.size()-1;j>0;j--)
            {
                int tmp=v[j];
                if(j==1)
                v[j]=value;
                else
                v[j]=v[j-1];

                if(j==v.size()-1)
                {
                    v.push_back(tmp);
                }
            }
        }
        else 
        {
            if(v.size()<1)
            {
              v.push_back(value);   
            }
            else if(v.size()==1)
            {
                int val=v[0];
                v[0]=value;
                v.push_back(val);
            }
            else
            {
               v.push_back(value);
               int val=v[v.size()-2];
               v[v.size()-2]=v[v.size()-1];
               v[v.size()-1]=val;

            }
        }
    }
    for(int j=0;j<v.size();j++)
            {
                cout<<v[j]<<" ";
            }
    return 0;
}