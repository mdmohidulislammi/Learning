#include <bits/stdc++.h>
using namespace std;
void merge(int a[],int left,int mid, int n)
{
    int leftS=mid-left+1;
    int rightS=n-mid;
    int L[leftS],R[rightS];
    int l=0;
    for(int i=0;i<leftS;i++)    
    {
        L[l]=a[i];l++;
    }
    l=0;
    for(int i=mid+1;i<=n;i++)
    {
        R[l]=a[i];
        l++;
    }
    int cur=left;
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
}
void merge_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        merge(a,l,mid,r);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    merge_sort(a, 0, n - 1);
    for(int val:a)
    cout<<val<<" ";
    return 0;
}