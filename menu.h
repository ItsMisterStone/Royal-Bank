#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menu_process(int account_number);
int actions(void);

int verify_pin(int account_number);
void update_structure(int account_number);

struct credentials
{
    int pin;
    int savings;
    int current;
}p1;


void menu_process(int account_number)
{
    int input = 0;
    update_structure(account_number);

    while (input != 4)
    {
        input = actions();

        if (input == 1)
        {
            check_balance(account_number);
        }
        else if (input == 2)
        {
            deposit(account_number);
        }
        else if (input == 3)
        {
            withdraw(account_number);
        }
        else if (input == 4)
        {
            printf("Goodbye! \n");
        }
        else
        {
            printf("Incorrect input. Please try again \n");
        }

    }
}


int actions(void)
{
    int temp;

    printf("Please pick one of the following options \n");
    printf("1. Check Balance \n");
    printf("2. Deposit cash \n");
    printf("3. Withdraw cash \n");
    printf("4. Quit \n");

    printf("Enter your choice: ");
    scanf("%d", &temp);
    return temp;

}

void update_structure(int account_number)
{
    FILE *file_struct1, *file_struct2, *file_struct3;

    file_struct1 = fopen("Pins.txt","r");
    file_struct2 = fopen("Savings Accounts.txt","r");
    file_struct3 = fopen("Current Accounts.txt","r");


    for (int i =0; i < account_number; i++)
    {
        fscanf(file_struct1, "%d", &p1.pin);
        fscanf(file_struct2, "%d", &p1.savings);
        fscanf(file_struct3, "%d", &p1.current);
    }

    fclose(file_struct1);
    fclose(file_struct2);
    fclose(file_struct3);
}

int verify_pin(int account_number)
{
    int temp_pin = 0;

    printf("Enter your 4 digit pin: ");
    scanf("%d",&temp_pin);

    if (temp_pin == p1.pin)
    {
        return 1;
    }
    else
    {
        printf("Invalid pin detected \n");
        return 0;
    }
}

#endif // MENU_H_INCLUDED
