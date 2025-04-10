#include<stdio.h>
int main()
{
    long long int a,b,c,sum,p,q,t,r,u,j,f,k;
    scanf("%lld %lld %lld",&a,&b,&c);
    if(a==0 && b>=1 && c>=1)
    {
        p=0;
        r=0;
        u=0;
    }
    else if(a>=1 && b>=1 && c>=1)
    {
        if(a<=b && a<=c)
        {
           p=a;
        }
        else if(b<=a && b<=c)
        {
            p=b;
        }
        else if(c<=a && c<=b)
        {
            p=c;
        }
        else
        {
            p=0;
        }
        q=a-p; t=c-p;
        if(q/2<=t)
        {
            r=q/2;
        }
        else if(t<=q/2)
        {
            r=t;
        }
        else
        {
            r=0;
        }
        u=0;
    }
     else if(a>=2 && b==0 && c>=1)
     {
          p=0;r=0;
         if(a>=2 && c>=1)
    {
        if(a/2<=c)
        {
            u=a/2;
        }
        else if(c<=a/2)
        {
            u=a/2;
        }
        else
        {
            u=0;
        }
    }
     }
 
  else
  {
    u=0;
  }    
    sum=p+r+u;
    printf("%lld",sum);
    return 0;
}