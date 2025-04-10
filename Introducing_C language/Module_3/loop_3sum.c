#include<stdio.h>
int main()
{
    int i,sum=0,n;
    scanf("%d",&n);
    for(i=1;i<=n;i+=1) //i=i+1 same to i+=1
    {
        sum+=i; //sum=sum+i; -same 
       // printf("%d",sum); if I want each time it has sum the value.
    }
    printf("%d",sum); //if I want all the value of sum in one .
    return 0;
}