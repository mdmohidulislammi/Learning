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
    int left=0,right=n-1;
    bool found=false;
    int target_value;
    cin>>target_value;
    while(left<=right)
    {
        int middle_index=(left+right)/2;
        if((target_value==a[middle_index] ) && (target_value==a[middle_index-1] || target_value==a[middle_index+1]))
        {
            found=true;
            break;
        }
        else if(target_value<a[middle_index])
        {
            right=middle_index-1;
        }
        else
        {
            left=middle_index+1;
        }
    }
    if(found==true) cout<<"found";
    else
    cout<<"not found";
    return 0;
}