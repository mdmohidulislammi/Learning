#include<bits/stdc++.h>
using namespace std;
class st
{
    public:
    string nm;
    int cls;
    string sec;
    int id;
    int math_mark;
    int eng_mark;
    int total;
};
bool sor(st a,st b)
{
    if(a.total==b.total)
    return a.id<b.id;
    else
    return a.total>b.total;
}
int main()
{
    int n;
    cin>>n;
    st a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].nm>>a[i].cls>>a[i].sec>>a[i].id>>a[i].math_mark>>a[i].eng_mark;
        a[i].total=a[i].math_mark+a[i].eng_mark;
    }
    sort(a,a+n,sor);
    for(int i=0;i<n;i++)
    {
        cout<<a[i].nm<<" "<<a[i].cls<<" "<<a[i].sec<<" "<<a[i].id<<" "<<a[i].math_mark<<" "<<a[i].eng_mark<<endl;
    }
    return 0;
}