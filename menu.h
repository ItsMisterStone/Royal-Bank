#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menu_process(int account_number); //The entire menu process will be done with this function
int actions(void); //Displays the actions the program can do and takes user input

int verify_pin(int account_number); //Verifies the users pin number
void update_structure(int account_number); //Updates the structure with the users information

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
            withdraw(account_number);
        }
        else if (input == 4)
        {
            printf("Goodbye! \n"); //Quits program afterwards
        }
        else //Invalid input message
        {
            printf("Incorrect input. Please try again \n");
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
        printf("Invalid pin detected \n");
        return 0;
    }
}

#endif // MENU_H_INCLUDED
