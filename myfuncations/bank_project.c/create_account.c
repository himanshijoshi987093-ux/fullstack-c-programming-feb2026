#include<stdio.h>
#include<string.h>
void createaccount();
void Deposit();
void withdraw();
void checkbalance();
void accountcreatedsuccessfully();
void choiceno();
int verifyNumberInstring(char stringdatap[12]);

int totalbalance = 0;
char mainAccount[12];
char name [50]; 
int accountCreated = 0 ;

int main()

{

    int choiceno;
    do
    {
        printf ("\n *****###### welcome to Banking System ######*****\n");
        printf("1. Create Account \n");
        printf("2. Deposit \n");
        printf("3. Withdraw \n");
        printf("4.Check Balance  \n");
        printf("5. Exit \n");

        printf(" Enter the choice number:");
        scanf("%d",&choiceno);

        switch(choiceno)
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
            default:choiceno;
            printf("Please enter correct choiceno:");

            while(choiceno !=5);
        }
        void createaccount()
        {
            printf(" Enter the only 11 digit for Account number:");
            scanf("%s", &mainAccount);
            if(strlen(mainAccount)!= 11 || ! verifyNumberInstring(mainAccount))
            {
                printf(" Error : Plese enter  account number agin (account no should be 11 digit)");
                return;
            }

            printf(" Plese enter account holer name:");
            scanf("[^\n]",name);
            printf(" Enter Opening Balance (minimum amount 500):");
            scanf(" %d",&totalbalance);
            

        }
    

        retur 0;
        
        

        
    } 
    
 







 

}
