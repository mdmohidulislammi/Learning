#include<stdio.h>
int main()
{
    int i;
    for(i=1;i<=100;i+=1)
    {
      /*  if(i==10)
        {
            break;  //if I don't want to see the value 10 
        }*/
        printf("%d\n",i);
          if(i==10)
        {
            break; //if I want to see the value 10
        }
    }
return 0;
}