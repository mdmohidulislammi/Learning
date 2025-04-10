#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    if (N>=0 && N%3==0)
{
    printf("YES");
}
else if (N>=0 && N!=0)
{
    printf("NO");
}
    return 0;
}