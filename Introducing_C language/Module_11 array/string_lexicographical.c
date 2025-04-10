#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100];
    scanf("%s %s",a,b);
    int i=0;
    while(1)
    {
        if(a[i]=='\0' && b[i]=='\0')
        {
            printf("Same");
            break;
        }
        else if(a[i]=='\0')
        {
            printf("A is small");
            break;
        }
        else if(b[i]=='\0')
        {
            printf("B is small");
            break;
        }
        if(a[i]==b[i])
        {
            i++;  
        }
        else if(a[i]<b[i])
        {
            printf("A is small");
            break;
        }
        else
        {
            printf("B is samall");
            break;
        }
    }    
    return 0;
}