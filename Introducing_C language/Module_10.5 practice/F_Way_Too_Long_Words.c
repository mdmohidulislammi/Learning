#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    char s[101],p,q;
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        if(strlen(s)<=10)
        {
            printf("%s\n",s);
        }
        else
        {
            int count=0;
            for(j=2;j<strlen(s);j++)
            {   
                count++;
            }
            p=s[0];q=s[strlen(s)-1];
            printf("%c%d%c\n",p,count,q);
        }
    }
    
    return 0;
}