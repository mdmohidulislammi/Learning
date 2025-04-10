#include<stdio.h>
int main()
{
    int tk;
    scanf("%d",&tk);
    if(tk>=5000)
    {
        printf("Go to Cox's Bazar. \n");
        if (tk>=10000)
        {
            printf("Go to Saint Martin.\n");
        }
        else 
        {
            printf("Then Back Home.\n");
        }
    }
    else 
    {
        printf("Kothao jabo na. Bashay thakbo.");
    }
    return 0;
}