#include<bits/stdc++.h>
using namespace std;
int main()
{
    int mina,tina, total;
    cin>>mina>>tina>>total;
    bool flag=false;
    for(int i=0;i<=total/min(mina,tina);i++)
    {
        int remain=total-(mina*i),rem=total-(tina*i);
        if(remain%tina==0 || rem%mina==0)
        flag=true;
    }
    if (flag==true)cout<<"YES";
    else cout<<"NO";
    return 0;
}