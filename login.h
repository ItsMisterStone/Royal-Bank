#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#include <dos.h>
#include <string.h>

int login_process(void); //The entire login function which is to be used in the main program
void user_pass(char *username, char *password); //Collects the username and password
int detect_account(char *username, char *password); // Verifies the username and password with the ones in the text file


int login_process(void)
{
    int flag = 0; //Keeps the infinite loop
    int account; //Creates account number which is used later in program
    char username[100];
    char password[100];

    while(flag != 1)
    {
      user_pass(username, password);
      account = detect_account(username, password); //Stores account number in 'account'

      if (account >= 1) //Proceeds if account number is detected
      {
          printf("Login successful \n");
          sleep(1);
          system("cls");

          return account; //Returns the account number for future use
      }
      else if (account == 0)
      {
          printf("Incorrect username or password \n");
      }
      else //Cancels program if no file is detected
      {
          return 0;
      }
    }
}


void user_pass(char *username, char *password) //Stores username and password using pointers
{
    printf("Enter your username: ");
    gets(username);

    printf("Enter your password: ");
    gets(password);
}

int detect_account(char *username, char *password)
{
    FILE *file_user,*file_pass; //Creates files and strings needed to find and store account credentials from the text files
    char real_user[100];
    char real_pass[100];
    int n = 1; //Value of account number

    file_user = fopen("Usernames.txt", "r");
    file_pass = fopen("Passwords.txt", "r");

    if (file_user == NULL || file_pass == NULL) //Quits if no file is detected
    {
        printf("Error opening files");
        return -1;
    }
    while (fgets(real_user, 100, file_user) && fgets(real_pass, 100, file_pass)) //Keeps running to match with the accounts in the text files
    {
        int len1 = strlen(real_user); //Variables to remove the extra newline in the text files
        int len2 = strlen(real_pass);

        real_user[len1 - 1] = '\0'; //Removes newline
        real_pass[len2 - 1] = '\0';

        if (strcmp(username, real_user) == 0 && strcmp(password, real_pass) == 0) //Matches username and password
        {
            fclose(file_user); //Closes files and returns with the account number
            fclose(file_pass);
            return n;
        }
        n++; //Changes account number
    }

    fclose(file_user); //Closes files and returns 0 since username or password was incorrect
    fclose(file_pass);
    return 0;
}

#endif // LOGIN_H_INCLUDED
