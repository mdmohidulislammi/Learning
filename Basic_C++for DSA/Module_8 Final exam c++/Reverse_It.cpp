#include<bits/stdc++.h>
using namespace std;
class st
{
    public:
    string nm;
    int cls;
    string sec;
    int id;
};
int main()
{
    int n;
    cin>>n;
    st a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].nm>>a[i].cls>>a[i].sec>>a[i].id;
    }
    int j=n-1;
    for(int i=0;i<j;i++)
    {
        swap(a[i].sec,a[j].sec);
        j--;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i].nm<<" "<<a[i].cls<<" "<<a[i].sec<<" "<<a[i].id<<endl;
    }
    return 0;
}