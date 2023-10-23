#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#include <dos.h>
#include <string.h>

int login_process(void);
void user_pass(char *username, char *password);
int detect_account(char *username, char *password);


int login_process(void)
{
    int flag = 0;
    char username[100];
    char password[100];

    while(flag != 1)
    {
      user_pass(username, password);

      if (detect_account(username, password) == 1)
      {
          printf("Login successful \n");
          sleep(1);
          system("cls");

          return 1;
      }
      else if (detect_account(username, password) == 0)
      {
          printf("Incorrect username or password \n");
      }
      else
      {
          return 0;
      }

    }
}

void user_pass(char *username, char *password)
{
    printf("Enter your username: ");
    gets(username);

    printf("Enter your password: ");
    gets(password);
}

int detect_account(char *username, char *password)
{
    FILE *file_user,*file_pass;
    char real_user[100];
    char real_pass[100];

    file_user = fopen("Usernames.txt", "r");
    file_pass = fopen("Passwords.txt", "r");

    if (file_user == NULL || file_pass == NULL)
    {
        printf("Error opening files");
        return 2;
    }
    while (fgets(real_user, 100, file_user) && fgets(real_pass, 100, file_pass))
    {
        int len1 = strlen(real_user);
        int len2 = strlen(real_pass);

        real_user[len1 - 1] = '\0';
        real_pass[len2 - 1] = '\0';

        if (strcmp(username, real_user) == 0 && strcmp(password, real_pass) == 0)
        {
            fclose(file_user);
            fclose(file_pass);
            return 1;
        }
    }

    fclose(file_user);
    fclose(file_pass);
    return 0;

}
#endif // LOGIN_H_INCLUDED
