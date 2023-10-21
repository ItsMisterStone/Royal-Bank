#ifndef SPLASH_H
#define SPLASH_H
#include <dos.h>

void splash_screen(void);
void print_1(void);
void print_2(void);
void print_3(void);
void create_bank(void);


void splash_screen(void)
{
    print_1();
    print_2();
    print_3();
    create_bank();

    system("cls");
}


void print_1(void)
{
  printf(".______      ______   ____    ____  ___       __         .______        ___      .__   __.  __  ___  \n");
  printf("|   _  \\    /  __  \\  \\   \\  /   / /   \\     |  |        |   _  \\      /   \\     |  \\ |  | |  |/  /  \n");
  sleep(1);
}

void print_2(void)
{
  printf("|  |_)  |  |  |  |  |  \\   \\/   / /  ^  \\    |  |        |  |_)  |    /  ^  \\    |   \\|  | |  '  /   \n");
  printf("|      /   |  |  |  |   \\_    _/ /  /_\\  \\   |  |        |   _  <    /  /_\\  \\   |  . `  | |    <    \n");
  sleep(1);
}

void print_3(void)
{
  printf("|  |\\  \\   |  `--'  |     |  |  /  _____  \\  |  `----.   |  |_)  |  /  _____  \\  |  |\\   | |  .  \\   \n");
  printf("| _| `._|   \\______/      |__| /__/     \\__\\ |_______|   |______/  /__/     \\__\\ |__| \\__| |__|\\__\\  \n\n");
  sleep(1);
}

void create_bank(void)
{
    FILE *file;
    char sentence[100];

    file = fopen("Royal Bank Logo.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file");
    }
    else
    {
        while (fgets(sentence, 100, file))
        {
            printf("%s", sentence);
        }
    }

    fclose(file);
    sleep(2);

}

#endif // SPLASH_H
