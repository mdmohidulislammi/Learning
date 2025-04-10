#include<stdio.h>
int main()
{
    int i;
    i=1;  //i=100;- loop work one time 
    do
    {
      printf("%d\n",i); 
      i+=1;
    } 
    while (i<=10);
    
    return 0;
}