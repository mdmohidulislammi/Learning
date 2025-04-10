#include<stdio.h>
#include<string.h>
void fun(char ar[])
{
    printf("%d",strlen(ar));
    printf("%s",ar);
}
int main()
{
    char ar[7688]="Hello";
    fun(ar);
    return 0;
}