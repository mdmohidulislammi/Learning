#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
 {
        scanf("%d",&a[i]);
}
int cnt[6]={0};// joto porjonto nite chai tar  theke 1 beshi nite hobe minimum.
                     // ekhane 0 to 5 e 6 ta number hoy tai 6 but 1 to 5 e 5 nilei hobe.
for(int i=0;i<n;i++)
{
    int val=a[i];
    cnt[val]++;//cnt[a[i]]++;  same 
}
for(int i=0;i<=5;i++)
{
    printf("%d - %d\n",i,cnt[i]);
}
/*
int z=0,o=0,t=0;
for(int i=0;i<n;i++)          // cnt[5]=0; 5 mane 5 porjonto value prorita koto bar ace 
                                check korar jonno.
{
    if(a[i]==0)
    {
        z++;
    }
    if(a[i]==1)
    {
        o++;
    }
    if(a[i]==2)
    {
        t++;
    }
    
}
     printf("0 - %d\n1 - %d\n2 - %d\n",z,o,t);*/
    return 0;
}