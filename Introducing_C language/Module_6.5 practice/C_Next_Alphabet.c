#include<stdio.h>
int main()
{
    char ch,sum;
    scanf("%c",&ch);
    if(ch>='a' || ch<='z')
    {
        if(ch=='z') {
            sum=ch-25;
        }
      else{  sum=ch+1;}
        printf("%c",sum);
    }
    
    return 0;
}