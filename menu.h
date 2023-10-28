#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#define SIZE 6

void menu_process(int account_number); //The entire menu process will be done with this function
int actions(void); //Displays the actions the program can do and takes user input
int verify_pin(int account_number); //Verifies the users pin number
void update_structure(int account_number); //Updates the structure with the users information

void check_balance(int account_number);
void deposit(int account_number);
void withdraw(int account_number);
void deposit_cash(int account_number, int deposit_amount, int deposit_account);
void withdraw_cash(int account_number, int withdraw_amount, int deposit_account);

struct credentials //Structure for storing the users information
{
    int pin;
    int savings;
    int current;
}p1;


void menu_process(int account_number)
{
    int input = 0; //For user input
    update_structure(account_number);

    while (input != 4) //Will keep running until user quits
    {
        input = actions(); //Stores user action input

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
            //withdraw(account_number);
            ;
        }
        else if (input == 4)
        {
            printf("\nGoodbye! \n"); //Quits program afterwards
        }
        else //Invalid input message
        {
            printf("Incorrect input. Please try again \n\n");
        }

    }
}

int actions(void)
{
    int temp; //For storing user input

    printf("Please pick one of the following options \n"); //Displays all the things the program can do
    printf("1. Check Balance \n");
    printf("2. Deposit cash \n");
    printf("3. Withdraw cash \n");
    printf("4. Quit \n");

    printf("Enter your choice: ");
    scanf("%d", &temp);
    return temp; //Returns user input

}

void update_structure(int account_number)
{
    FILE *file_struct1, *file_struct2, *file_struct3; //Files for updating structure values

    file_struct1 = fopen("Pins.txt","r"); //Opens all the files
    file_struct2 = fopen("Savings Accounts.txt","r");
    file_struct3 = fopen("Current Accounts.txt","r");

    for (int i =0; i < account_number; i++) //Locates the information of the account
    {
        fscanf(file_struct1, "%d", &p1.pin); //Store the information of the account
        fscanf(file_struct2, "%d", &p1.savings);
        fscanf(file_struct3, "%d", &p1.current);
    }
    fclose(file_struct1); // Closes all the files
    fclose(file_struct2);
    fclose(file_struct3);
}

int verify_pin(int account_number)
{
    int temp_pin = 0; //For storing pin number

    printf("Enter your 4 digit pin: ");
    scanf("%d",&temp_pin);

    if (temp_pin == p1.pin) //Checks pin
    {
        return 1;
    }
    else //Invalid pin
    {
        printf("Invalid pin detected \n\n");
        return 0;
    }
}

void check_balance(int account_number)
{
    update_structure(account_number);
    if (verify_pin(account_number))
    {
        int temp_balance_flag = 0;

        printf("\nWhich account would you like to check the balance of \n");
        printf("1. Savings account \n");
        printf("2. Current account \n");
        printf("3. Return to main menu \n");

        printf("Enter your choice: ");
        scanf("%d", &temp_balance_flag);
        printf("\n");

        if (temp_balance_flag == 1)
        {
            printf("Your balance is %d taka \n\n", p1.savings);
        }
        else if (temp_balance_flag == 2)
        {
            printf("Your balance is %d taka \n\n", p1.current);
        }
        else if (temp_balance_flag == 3)
        {
            ;
        }
        else
        {
            printf("Invalid input. Please re-verify your pin and try again \n");
            check_balance(account_number);
        }
    }
}

void deposit(int account_number)
{
    if (verify_pin(account_number))
    {
        int temp_deposit_flag = 0;

        printf("\nWhich account would you like to deposit to \n");
        printf("1. Savings account \n");
        printf("2. Current account \n");
        printf("3. Return to main menu \n");

        printf("Enter your choice: ");
        scanf("%d", &temp_deposit_flag);
        printf("\n");

        if (temp_deposit_flag == 1)
        {
            int deposit_amount = 1, deposit_account = 1;

            while (deposit_amount % 500 != 0)
            {
                printf("You can only deposit cash in increments of 500 or 1000 with a minimum deposit amount of 500 \n");
                printf("Enter the amount of money you would like to deposit: ");
                scanf("%d", &deposit_amount);

                if (deposit_amount % 500 == 0)
                {
                    deposit_cash(account_number, deposit_amount, deposit_account);
                }
                else
                {
                    printf("Invalid input.Please try again \n");
                }
            }
        }
        else if (temp_deposit_flag == 2)
        {
            int deposit_amount = 1, deposit_account = 2;

            while (deposit_amount % 500 != 0)
            {
                printf("You can only deposit cash in increments of 500 or 1000 with a minimum deposit amount of 500 \n");
                printf("Enter the amount of money you would like to deposit: ");
                scanf("%d", &deposit_amount);

                if (deposit_amount % 500 == 0)
                {
                    deposit_cash(account_number, deposit_amount, deposit_account);
                }
                else
                {
                    printf("Invalid input.Please try again \n");
                }
            }
        }
        else if (temp_deposit_flag == 3)
        {
            ;
        }
        else
        {
            printf("Invalid input. Please re-verify your pin and try again \n");
            check_balance(account_number);
        }
    }
}
void deposit_cash(int account_number, int deposit_amount, int deposit_account)
{
    FILE *file_deposit_saving, *file_deposit_current;
    int input[SIZE], i = 0;

    if (deposit_account == 1)
    {
        file_deposit_saving = fopen("Savings Accounts.txt","r+");

        int status = fscanf(file_deposit_saving, "%d", &input[i]);
        for (i = 1; status == 1; i++)
        {
            status = fscanf(file_deposit_saving, "%d", &input[i]);
        }

        input[account_number - 1] += deposit_amount;
        file_deposit_saving = fopen("Savings Accounts.txt","w");
        for (int j = 0; j < SIZE; j++)
        {
            fprintf(file_deposit_saving, "%d\n", input[j]);
        }

        fclose(file_deposit_saving);
    }
    else
    {
        file_deposit_current = fopen("Current Accounts.txt","r+");

        int status = fscanf(file_deposit_current, "%d", &input[i]);
        for (i = 1; status == 1; i++)
        {
            status = fscanf(file_deposit_current, "%d", &input[i]);
        }

        input[account_number - 1] += deposit_amount;
        file_deposit_current = fopen("Current Accounts.txt","w");
        for (int j = 0; j < SIZE; j++)
        {
            fprintf(file_deposit_current, "%d\n", input[j]);
        }

        fclose(file_deposit_current);
    }

}

#endif // MENU_H_INCLUDED
