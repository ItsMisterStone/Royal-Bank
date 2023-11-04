#include <stdio.h>
#include "splash.h"
#include "login.h"
#include "menu.h"

int main(void)
{
    int account_number; //For storing account number

    splash_screen();
    account_number = login_process(); //Stores the account number

    if (account_number)
    {
        menu_process(account_number); //Uses account number in the menu process
    }
    else
    {
        printf("Files not detected"); //Error message
    }

    return 0;
}

