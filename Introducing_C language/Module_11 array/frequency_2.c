#include<stdio.h>
#include<string.h>
int main()
{
    char s[100],i;
    scanf("%s",s);
     int cnt[26]={0};
    for(i=0;i<strlen(s);i++)   
    {
        int value=s[i]-'a';
        cnt[value]++;
    }
   /* for(i=0;i<strlen(s);i++)
    {
        int value=s[i]-'a';        
        if(cnt[value]!=0)
        {
            printf("%c --%d",value+'a',cnt[value]);
        }
        cnt[value]=0;
    }*/
    for(i=0;i<26;i++)
    {  if(cnt[i]!=0)
    {
        printf("%c --%d\n",i+'a',cnt[i]);
    }
    }
    return 0;
}