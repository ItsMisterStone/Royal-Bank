#ifndef SPLASH_H
#define SPLASH_H
#include <dos.h>

void splash_screen(void); //The full splash screen function to use in the main program
void print_1(void); //Functions to print the word "Royal Bank" in three separate parts
void print_2(void);
void print_3(void);
void create_bank(void); //Creates the image of the bank


void splash_screen(void)
{
    print_1();
    print_2();
    print_3();
    create_bank();

    system("cls"); //Clears the screen
}


void print_1(void) //First part of "Royal Bank"
{
  printf(".______      ______   ____    ____  ___       __         .______        ___      .__   __.  __  ___  \n");
  printf("|   _  \\    /  __  \\  \\   \\  /   / /   \\     |  |        |   _  \\      /   \\     |  \\ |  | |  |/  /  \n");
  sleep(1);
}

void print_2(void) //Second part of "Royal Bank"
{
  printf("|  |_)  |  |  |  |  |  \\   \\/   / /  ^  \\    |  |        |  |_)  |    /  ^  \\    |   \\|  | |  '  /   \n");
  printf("|      /   |  |  |  |   \\_    _/ /  /_\\  \\   |  |        |   _  <    /  /_\\  \\   |  . `  | |    <    \n");
  sleep(1);
}

void print_3(void) //Third part of "Royal Bank"
{
  printf("|  |\\  \\   |  `--'  |     |  |  /  _____  \\  |  `----.   |  |_)  |  /  _____  \\  |  |\\   | |  .  \\   \n");
  printf("| _| `._|   \\______/      |__| /__/     \\__\\ |_______|   |______/  /__/     \\__\\ |__| \\__| |__|\\__\\  \n\n");
  sleep(1);
}

void create_bank(void)
{
    FILE *file;
    char sentence[100]; //An array to store strings while printing

    file = fopen("Royal Bank Logo.txt", "r"); //Opens the required file

    if (file == NULL) //No file detected
    {
        printf("Error opening file");
    }
    else
    {
        while (fgets(sentence, 100, file)) //Keeps running until the file is empty and out of strings
        {
            printf("%s", sentence);
        }
    }

    fclose(file);
    sleep(2);
}

#endif // SPLASH_H
