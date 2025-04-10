#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main()
{
    char s[100];
    int a;
    cin>>s;
    getchar();//-for enter
    cin>> a;
 //   fgets(s,sizeof(s),stdin);
    cin.getline(s,sizeof(s));
    cout<<s<<endl;
    //cout<< strlen(s)<<endl;
    /*int n;
    cin>>n;
    //int ar[n];
  /*  for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }*/
    return 0;
}