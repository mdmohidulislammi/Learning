#include<stdio.h>
int main()
{
    int ar[5]={10,20,30,50,40};
  //  printf("0th index er address - -%p\n",&ar);
    //printf("0th index er address - %p\n",ar);
    //printf("0th index er value - %d\n",ar[0]);
   // printf("0th index er value - %d\n",*ar);
    printf("1th index er value - %d\n",ar[1]);
     printf("1th index er value - %d\n",*(ar+1));
    printf("%d\n",*(ar+1));
    //ar[1] -->*(ar+1)-->1[ar] --- same;
    printf("%d\n",1[ar]);

    return 0;
}