#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int left=0,right=n-1;
    bool found=false;
    while(left<=right)
    {
        int middle_index=(left+right)/2,target_value;
        cin>>target_value;
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
            //move to right;
            left=middle_index+1;
        }                
    }
    if(found==true)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}