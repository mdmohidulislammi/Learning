#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    while(q--)
    {
        int left=0,right=n-1,target_value;
        bool found=false;
        cin>>target_value;
        while(left<=right)
        {
           int middle_index=(left+right)/2;
           if(target_value==a[middle_index])
           {
             found=true;
             break;
           }
           else if(target_value<a[middle_index])
           {
            //move to left
            right=middle_index-1;
           }
           else
           {
            //move to right
            left=middle_index+1;
           }
        }
        if(found==true) cout<<"found"<<endl;
        else
        cout<<"not found"<<endl;
    }

    return 0;
}