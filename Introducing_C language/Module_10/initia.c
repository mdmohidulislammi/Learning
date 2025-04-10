#include<stdio.h>
int main()
{
    //char ar[]={'M','o','h','i','d','u','l'} -no guarantee for null
   // char ar[]="Mohidul\0";
   char ar[]="Mohidul\n";//guarantee for null.

for(int i=0;i<8;i++)
{
    printf("%c",ar[i]);
}
    printf("%s ",ar);
    return 0;
}