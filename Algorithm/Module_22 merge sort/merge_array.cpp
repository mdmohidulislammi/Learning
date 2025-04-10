#include <bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int r, int n )
{
    int leftS=r-l+1;
    int rightS=n-r;
    int L[leftS],R[rightS];
    int l=0;
    for(int i=0;i<leftS;i++)    
    {
        L[l]=a[i];l++;
    }
    l=0;
    for(int i=r+1;i<=n;i++)
    {
        R[l]=a[i];
        l++;
    }
    int cur=l;
    int i=0,j=0;
    while(i<leftS && j<rightS)
    {
        if(L[i]<=R[j])
        {
            a[cur]=L[i];
            i++;
        }
        else
        {
            a[cur]=R[j];
            j++;
        }
        cur++;
    }
    while(i<leftS)
    {
        a[cur]=L[i];
        i++;
        cur++;
    }
    while(j<rightS)
    {
        a[cur]=R[j];
        j++;
        cur++;
    }
    // for(int i=0;i<=n;i++)
    // {
    //     cout<<a[i]<<" ";
    // }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    merge(a,0,3,n-1);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}