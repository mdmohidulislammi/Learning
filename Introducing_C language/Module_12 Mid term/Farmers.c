#include<stdio.h>
int main()
{
    int n,i,m1,m2,d,few;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d\n",&m1,&m2,&d);
        few=d-(m1*d/(m1+m2));
        printf("%d\n",few);
    }
    return 0;
}