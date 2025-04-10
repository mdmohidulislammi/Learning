#include<stdio.h>
#include<string.h>
int main()
{
    char a[22],b[11],c[22];
    scanf("%s %s",a,b);
    printf("%d %d\n",strlen(a),strlen(b));
    int j=strlen(a);
    for(int i=0;i<strlen(a)+strlen(b);i++)
    {
       a[j]=b[i];
       j++;
    }
    printf("%s\n",a);
    for(int i=0;i<strlen(a);i++)
    {
      
       c[i]=a[i];
       c[strlen(a)-strlen(b)]='\0';
    }
     char x=c[0];
       c[0]=b[0];
       b[0]=x;
    printf("%s %s",c,b);
    return 0;
}