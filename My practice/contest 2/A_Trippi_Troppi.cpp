#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for (int i = 0; i <= t; i++)
    {
        string s;
        getline(cin,s);
        string str;
        stringstream ss(s);
        string word;
        while (ss>> word)
        {
            str.push_back(word[0]);
        }
        cout<<str<<endl;
    }
    
    return 0;
}