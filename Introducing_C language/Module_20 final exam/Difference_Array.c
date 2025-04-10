#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        int a[n],b[n],c[n];
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        for(int j=0;j<n;j++)
        {
            b[j]=a[j];
        }
        for(int j=0;j<n-1;j++)
        {
            for(int p=j+1;p<n;p++)
            {
                if(b[j]>b[p])
                {
                  int s=b[j];
                  b[j]=b[p];
                  b[p]=s;
                }
            }
        }
        for(int j=0;j<n;j++)
        {
            c[j]=a[j]-b[j];
        }
       for(int j=0;j<n;j++)
        {
            if(c[j]<0)
            {
                printf("%d ",-c[j]);
            }
            else
            {
                printf("%d ",c[j]);
            }
        }
        printf("\n");
    }
    return 0;
}