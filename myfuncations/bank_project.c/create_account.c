#include<stdio.h>
#include<string.h>
void createaccount();
void Deposit();
void withdraw();
void checkblance();
void accountcreatedsuccessfully();
void choiceno();
int verifyNumberInstring(char stringdatap[11]);
int totalblance;
char MainAccount[11];

int main()

{

    int choiceno;
printf("#########Banking Management System ###########\n");

 printf("1. Create account:");
 Printf("2.Withdraw amount:");
 printf("3.Deposit Amount:");
 printf("4.Check Blance:");
 peintf("5.Exit");


do 
{

    printf("\n Please enter any choiceno number for account:\n");
    scanf("%d",& choiceno);

    switch (choiceno)
{
    case 1:
    createaccount();
    printf("\nplease enter the 11 digit number for create user account number:");
    scanf("%d",&verifyNumberInstring);
    break;
    case 2:
    Deposit();

    break;
    case 3:
    withdraw();
    break;

    case 4:
    checkblance();

    break;
    case 5:
    accountcreatedsuccessfully();
    break;

    default:
    printf(" \nError: please enter correct choise number");

}

}

return 0;

}