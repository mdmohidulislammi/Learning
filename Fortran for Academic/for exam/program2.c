#include<stdio.h>

#define maxLoan 50000
int main()
{
    int loan1, loan2, loan3, loan23, sanc;
    printf("Enter the previous  loans : ");
    scanf("%d %d ", &loan1,&loan2);
    printf("\nEnter loan\n: ");
    scanf("%d", &loan3);
    loan23=loan2+loan3;
    sanc=(loan1>0)?0: ((loan23>maxLoan)?loan2 : loan3);
    printf("The pending loans : %d %d", loan1, loan2);
    printf("\nThe sanctioned : %d", sanc);
    printf("\n The new loan %d ", loan3);
    // if(loan1 ==0)
    // {
    //     if(loan23 <= maxLoan)
    //     printf("Loan sanctioned : %d",loan3 );
    //     else 
    //     {
    //        printf("Loan sanctioned : %d", maxLoan-loan2);
    //     }
    // }
    
    return 0;
}