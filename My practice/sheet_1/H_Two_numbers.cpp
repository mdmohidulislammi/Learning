#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a%b==0)
    {
        cout<<"floor "<<a<<" / "<<b<<" = "<<a/b<<endl<<"ceil "<<a<<" / "<<b<<" = "<<a/b<<endl<<"round "<<a<<" / "<<b<<" = "<<a/b<<endl;
    }
    else
    {
        int fl=a/b,cl=(a/b)+1;
        float num=(float)a/b;
        int r;
        if(fl+.5<=num)
        r=cl;
        else {r=fl;}
        cout<<"floor "<<a<<" / "<<b<<" = "<<fl<<endl<<"ceil "<<a<<" / "<<b<<" = "<<cl<<endl<<"round "<<a<<" / "<<b<<" = "<<r<<endl;
    }
    return 0;
}