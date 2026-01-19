#include <stdio.h>
#include <stdlib.h>

/* Structure for bank account */
struct Bank
{
    int accNo;
    char name[50];
    float balance;
};

/* Function declarations */
void createAccount();
void deposit();
void withdraw();
void checkBalance();

int main()
{
    int choice;

    do
    {
        printf("\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Balance Enquiry\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                checkBalance();
                break;

            case 5:
                printf("Thank you for using Bank System!\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}

/* Create new account */
void createAccount()
{
    struct Bank b;
    FILE *fp;

    fp = fopen("bank.txt", "ab");

    printf("Enter Account Number: ");
    scanf("%d", &b.accNo);
    printf("Enter Name: ");
    scanf("%s", b.name);
    printf("Enter Initial Balance: ");
    scanf("%f", &b.balance);

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf("Account Created Successfully!\n");
}

/* Deposit money */
void deposit()
{
    struct Bank b;
    FILE *fp;
    int acc;
    float amt;
    int found = 0;

    fp = fopen("bank.txt", "rb+");

    printf("Enter Account Number: ");
    scanf("%d", &acc);
    printf("Enter Amount to Deposit: ");
    scanf("%f", &amt);

    while(fread(&b, sizeof(b), 1, fp))
    {
        if(b.accNo == acc)
        {
            b.balance += amt;
            fseek(fp, -sizeof(b), SEEK_CUR);
            fwrite(&b, sizeof(b), 1, fp);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if(found)
        printf("Amount Deposited Successfully!\n");
    else
        printf("Account Not Found!\n");
}

/* Withdraw money */
void withdraw()
{
    struct Bank b;
    FILE *fp;
    int acc;
    float amt;
    int found = 0;

    fp = fopen("bank.txt", "rb+");

    printf("Enter Account Number: ");
    scanf("%d", &acc);
    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amt);

    while(fread(&b, sizeof(b), 1, fp))
    {
        if(b.accNo == acc)
        {
            if(b.balance >= amt)
            {
                b.balance -= amt;
                fseek(fp, -sizeof(b), SEEK_CUR);
                fwrite(&b, sizeof(b), 1, fp);
                printf("Withdrawal Successful!\n");
            }
            else
            {
                printf("Insufficient Balance!\n");
            }
            found = 1;
            break;
        }
    }

    fclose(fp);

    if(!found)
        printf("Account Not Found!\n");
}

/* Balance enquiry */
void checkBalance()
{
    struct Bank b;
    FILE *fp;
    int acc;
    int found = 0;

    fp = fopen("bank.txt", "rb");

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    while(fread(&b, sizeof(b), 1, fp))
    {
        if(b.accNo == acc)
        {
            printf("Account Holder: %s\n", b.name);
            printf("Available Balance: %.2f\n", b.balance);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if(!found)
        printf("Account Not Found!\n");
}
