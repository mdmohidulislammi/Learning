#include<bits/stdc++.h>
using namespace std;
void ref(string& s)
{
    s="Heoolo sjf world";
    //cout <<s<<endl;-print korle ja s e dibo tai hobe like fun;
}
int main()
{
    string s;
    getline(cin,s);
    ref(s);
    cout<<s;
    return 0;
}