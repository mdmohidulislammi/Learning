#include<stdio.h>
int main()
{
    int n,p;
    float o;
    scanf("%d %d",&n,&p);
    o=(100*p)*1.0/(100-n);
    printf("%.2f",o);
    return 0;    
}