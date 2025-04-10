#include<bits/stdc++.h>
using namespace std;
class st
{
    public:
    char ch;
    int count;
};
bool cmp(st a , st b)
{
     if(a.count==b.count)
     {
        return a.ch<b.ch;
     }
     else
     return a.count>b.count;
}
int main()
{
    string s;
    getline(cin,s);
    st a[26];
    for(int i=0;i<26;i++)
    {
        a[i].ch=char(i+'a');
        a[i].count=0;
    }
    for(char c:s)
    {
        int ascii=c-'a';
        a[ascii].count++;
    }
    sort(a,a+26,cmp);
    for(int i=0;i<26;i++)
    {
       /* if(a[i].count!=0)
        {
           // cout<<a[i].ch <<" "<<a[i].count<<endl;
        }*/
        for(int j=0;j<a[i].count;j++)
        cout<<a[i].ch;
    }
    return 0;
}