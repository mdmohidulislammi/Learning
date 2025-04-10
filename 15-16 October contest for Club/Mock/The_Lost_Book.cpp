#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int book;
    cin>>book;
    bool find=false;
    int found=-1;
    for(int i=0;i<n;i++)
    {
        if(book==a[i])
        {
            found=i;
            find=true;
        }
    }
    if(find) cout<<found;
    else cout<<found;
    return 0;
}