#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,p=0,t=0;
        scanf("%d",&n);
        char s[100000];
        scanf("%s",s);
        for(int j=0;j<strlen(s);j++)
        {
            if(s[j]=='T')
            {
                t++;
            }
            if(s[j]=='P')
            {
                p++;
            }
        }
        if(p>t)
        {
            printf("Pathaan\n");
        }
        else if(p<t)
        {
            printf("Tiger\n");
        }
        else
        {
            printf("Draw\n");
        }
    }
    return 0;
}