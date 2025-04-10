#include<stdio.h>
int main()
{
    char c;
    int p[26]={0};
    while(scanf("%c",&c) != EOF)
    {
        int a=c-'a';
        p[a]++;
    }
    for(int i=0;i<26;i++)
    {
        if(p[i]!=0)
        {
            printf("%c : %d\n",i+'a',p[i]);
        }
        
    }
    return 0;
}