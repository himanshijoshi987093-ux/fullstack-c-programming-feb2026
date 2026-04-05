#include <stdio.h>
#include <string.h>

// Function declarations
void createaccount();
void Deposit();
void withdraw();
void checkbalance();
void accountcreatedsuccessfully();
int verifyNumberInstring(char stringdata[12]);

// Global variables
int totalbalance = 0;
char mainAccount[12];
char name[50];
int accountCreated = 0;

int main()
{
    int choice;

    do
    {
        printf("\n**###### Welcome to Banking System ######**\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
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
            printf("Thank you for using our bank!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

// Create Account
void createaccount()
{
    printf("Enter 11-digit Account Number: ");
    scanf(" %11s", mainAccount);

    if (strlen(mainAccount) != 11 || !verifyNumberInstring(mainAccount))
    {
        printf("Error: Account number must be exactly 11 digits.\n");
        return;
    }

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Opening Balance (minimum 500): ");
    scanf("%d", &totalbalance);

    if (totalbalance < 500)
    {
        printf("Error: Minimum balance should be 500.\n");
        return;
    }

    accountCreated = 1;
    accountcreatedsuccessfully();
}

// Deposit
void Deposit()
{
    int amount;

    if (!accountCreated)
    {
        printf("Please create an account first.\n");
        return;
    }

    printf("Enter deposit amount (minimum 100): ");
    scanf("%d", &amount);

    if (amount < 100)
    {
        printf("Error: Minimum deposit is 100.\n");
        return;
    }

    totalbalance += amount;
    printf("Deposit successful.\n");
}

// Withdraw
void withdraw()
{
    int amount;

    if (!accountCreated)
    {
        printf("Please create an account first.\n");
        return;
    }

    printf("Enter withdraw amount: ");
    scanf("%d", &amount);

    if (amount > totalbalance)
    {
        printf("Error: Insufficient balance.\n");
        return;
    }

    totalbalance -= amount;
    printf("Withdrawal successful.\n");
}

// Check Balance
void checkbalance()
{
    if (!accountCreated)
    {
        printf("Please create an account first.\n");
        return;
    }

    printf("\n** Account Details **\n");
    printf("Account Number : %s\n", mainAccount);
    printf("Account Holder : %s\n", name);
    printf("Balance        : %d\n", totalbalance);
}

// Success Message
void accountcreatedsuccessfully()
{
    printf("\nAccount created successfully!\n");
}

// Verify numeric string
int verifyNumberInstring(char stringdata[12])
{
    for (int i = 0; stringdata[i] != '\0'; i++)
    {
        if (stringdata[i] < '0' || stringdata[i] > '9')
        {
            return 0; // invalid
        }
    }
    return 1; // valid
}















