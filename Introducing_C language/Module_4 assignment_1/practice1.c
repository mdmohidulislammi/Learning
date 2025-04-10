#include<stdio.h>
int main()
{
    int a;
    long long int b;
    char ch;
    float d;
    double e;
    scanf("%d %lld %c %f %lf",&a, &b, &ch, &d, &e);
    printf("%d\n%lld\n%c\n%.2f\n%.1lf",a,b,ch,d,e);
    return 0;
}