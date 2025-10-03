#include <stdio.h>
int main()
{
    int num;
    printf("Enter the number  : ");
    scanf("%d", &num);
    int a[100000],n=0;
    while (num>0)
    {
        a[n]=num%10;
        num=num/10;
        n++;
    }
    for (int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i] <= a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    return 0;
}