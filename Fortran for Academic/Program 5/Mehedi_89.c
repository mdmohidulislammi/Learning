#include <stdio.h>
int main()
{
    int Dept, Lvl;
    printf("Enter the department No. \n1. Hr\n2. IT\n3. Sales. \n");
    scanf("%d", &Dept);
    printf("Enter the employee No. \n1. Junior\n2. Mid\n3. Senior\n");
    scanf("%d", &Lvl);
    switch (Dept)
    {
    case 1:
    {
        switch (Lvl)
        {
        case 1:printf("Salary is 30k . "); break;
        case 2:printf("Salary is 50k.");  break;
        case 3:printf("Salary is 60k."); break;
        default:printf("Your input is invalid."); break;
        }
    } break;
    case 2:
    {
        switch (Lvl)
        {
        case 1:printf("Salary is 15k.");break;
        case 2:printf("Salary is 20k."); break;
        case 3:printf("Salary is 25k.");break;
        default:printf("Your input is wrong."); break;
        }
    }break;
    case 3:
    {
        switch (Lvl)
        {
        case 1:printf("Salary is 10k.");break;
        case 2:printf("Salary is 15k."); break;
        case 3:printf("Salary is 20k."); break;
        default:printf("Your input is wrong.");break;
        }
    }break;
    }
    return 0;
}