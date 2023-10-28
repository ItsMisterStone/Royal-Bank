#include <stdio.h>
#include "splash.h"
#include "login.h"
#include "menu.h"

int main(void)
{
    int account_number;

    splash_screen();
    account_number = login_process();

    if (account_number)
    {
        menu_process(account_number);
    }
    else
    {
        printf("File not detected");
    }

    return 0;
}
