#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    stringstream ss(s),pp(s);
    string word,wo;
    int cnt=0;
    while(pp>>wo)
    {
        cnt++;
    }
    int p=0;
    while(ss>>word)
    {
        int j=word.size()-1;
        for(int i=0;i<j;i++)
        {
            char t=word[i];
            word[i]=word[j];
            word[j]=t;
            j--;
        }
        p++;
        cout<<word;
        if(p==cnt)
        {
            break;
        }
        else
        {
            cout<<" ";
        }       
    }
    return 0;
}