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
};
bool sor(st a,st b)
{
    if(a.eng_mark==b.eng_mark)
    {
        if(a.math_mark==b.math_mark)
        return a.id<b.id;
        else
        return a.math_mark>b.math_mark;
    }
    else
    return a.eng_mark>b.eng_mark;
}
int main()
{
    int n;
    cin>>n;
    st a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].nm>>a[i].cls>>a[i].sec>>a[i].id>>a[i].math_mark>>a[i].eng_mark;        
    }
    sort(a,a+n,sor);
    for(int i=0;i<n;i++)
    {
        cout<<a[i].nm<<" "<<a[i].cls<<" "<<a[i].sec<<" "<<a[i].id<<" "<<a[i].math_mark<<" "<<a[i].eng_mark<<endl;
    }
    return 0;
}