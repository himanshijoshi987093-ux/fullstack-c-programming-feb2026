#include <stdio.h>
#include <string.h>
void createaccount();
void Deposit();
void withdraw();
void checkbalance();
void accountcreatedsuccessfully();
void choiceno();
int verifyNumberInstring(char stringdatap[12]);

int totalbalance = 0;
char mainAccount[12];
char name[50];
int accountCreated = 0;
int amount;

int main()

{
    int choiceno;
    do
    {
        printf("\n *****###### welcome to Banking System ######*****\n");
        printf("1. Create Account \n");
        printf("2. Deposit \n");
        printf("3. Withdraw \n");
        printf("4.Check Balance  \n");
        printf("5. Exit \n");

        printf(" Enter the choice number:");
        scanf("%d", &choiceno);

        switch (choiceno)
        {
        case 1:
            createaccount();
            break;
        case 2:
            Deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            checkbalance();
            break;
        case 5:
            printf(" Thank You to Open your account our bank!\n");
        default:
            choiceno;
            printf("Please enter correct choiceno:");
        }
    }

    while (choiceno != 5);
}
void createaccount()
{
    printf(" Enter the only 11 digit for Account number:");
    scanf(" %11s", mainAccount);
    if (strlen(mainAccount) != 11 || !verifyNumberInstring(mainAccount))
    {
        printf(" Error : Plese enter  account number agin (account no should be 11 digit)");
        return;
    }

    printf(" Plese enter account holer name:");
    scanf("%[^\n]", name);
    printf(" erroe:Enter Opening Balance (minimum amount 500):");
    scanf(" %d", &totalbalance);

    if (totalbalance < 500)
    {
        printf("Error: Eenter Minimum balance should be 500\n");
        return;
    }
    accountCreated = 1;
    accountcreatedsuccessfully();
}
void Deposit()
{

    if (!accountCreated)
    {
        printf("Before deposit You need to Open first account\n");
        return;
    }
    printf(" Enter amount (main 100):");
    scanf("%d", &amount);
    if (amount < 100)
    {
        printf("error:( Minimum deposit is 100)\n");
        return;
    }
    totalbalance += amount;
    printf("Deposit successful\n");
}

    void withdraw()
    {
        int amount;
        {
           if (!accountCreated)
            printf("Before deposit You need to Open first account\n");
           return;
        }
    
    printf(" Enter the withdraw amount :");
    scanf("%d", &amount);

    if (amount > totalbalance)
    {
        printf("Maxmimum amount should be 500");
        return;
    }
    totalbalance =totalbalance - amount;
    printf(" Withdrawal successful\n");
}

void checkbalance()
{
    if (!accountCreated)
    {

        printf("You need to Open first account\n");
        return;
    }

    printf("\n***Account Details***\n");
    printf("Account Number :%s\n", mainAccount);
    printf(" Account holder Name: %s\n", name);
    printf(" Balance:%d\n", totalbalance);
}
void accountcreatedsuccessfully()
{
    printf("\n Account created successfully\n");
}
void choiceno()
{
    printf(" Error : Please enter correct choiceno \n");
}
int verifyNumberInstring(char stringdata[12])

{
    for (int i = 0; stringdata[i] != '\0'; i++)
    {
        if (stringdata[i] < '0' || stringdata[i] > '9')
        {
            return 1; // invalid
        }
    }
    return 1; // valid
}