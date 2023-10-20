#ifndef SPLASH_H
#define SPLASH_H

void splash_screen(void);
void print_1(void);
void print_2(void);
void print_3(void);



void splash_screen(void)
{
    print_1();
    print_2();
    print_3();
}


void print_1(void)
{
  printf(".______      ______   ____    ____  ___       __         .______        ___      .__   __.  __  ___  \n");
  printf("|   _  \\    /  __  \\  \\   \\  /   / /   \\     |  |        |   _  \\      /   \\     |  \\ |  | |  |/  /  \n");
}

void print_2(void)
{
  printf("|  |_)  |  |  |  |  |  \\   \\/   / /  ^  \\    |  |        |  |_)  |    /  ^  \\    |   \\|  | |  '  /   \n");
  printf("|      /   |  |  |  |   \\_    _/ /  /_\\  \\   |  |        |   _  <    /  /_\\  \\   |  . `  | |    <    \n");
}

void print_3(void)
{
  printf("|  |\\  \\   |  `--'  |     |  |  /  _____  \\  |  `----.   |  |_)  |  /  _____  \\  |  |\\   | |  .  \\   \n");
  printf("| _| `._|   \\______/      |__| /__/     \\__\\ |_______|   |______/  /__/     \\__\\ |__| \\__| |__|\\__\\  \n");
}






#endif // SPLASH_H
