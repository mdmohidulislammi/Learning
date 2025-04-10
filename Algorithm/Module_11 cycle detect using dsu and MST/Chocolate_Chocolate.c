#include<stdio.h>
int chocolate(int remain, int total_ch)
{
    if(remain<3) return total_ch;
    int available=remain/3;
    total_ch+=available;
    chocolate(available, total_ch);
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int i=0;i<test;i++)
    {
        int taka;
        scanf("%d",& taka);
        int first=taka/5;
        int total=chocolate(first,first);
        printf("%d\n",total);
    }
    return 0;
}