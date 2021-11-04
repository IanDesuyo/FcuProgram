#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guessGame(void);        // function prototype
int isCorrect(int, int);     // function prototype
void printTamagotchi(void);  // function prototype

int main(void) {
    srand(time(NULL));  // seed random number generator
    guessGame();
}

// guessGame generates numbers between 1 and 1000
// and checks bot's guess
void guessGame(void) {
    int answer;         // randomly generated number
    int guess;          // bot's guess
    int response;       // 1 or 2 response to continue game
    int ansRange[2];    // bot's guess range
    int guessResponse;  // isCorrect response, -1 = too low, 0 = correct, 1 = too high
    int count;          // guess count
    int guessAlgorithm;

    // loop until user types 2 to quit game
    do {
        // generate random number between 1 and 1000
        // 1 is shift, 1000 is scaling factor
        answer = 1 + rand() % 1000;
        ansRange[0] = 1;
        ansRange[1] = 1000;
        guessResponse = 1;
        count = 0;

        printf("Please select guess algorithm for this round.\n( 1=binary search, 2=random, 3=1 to 1000, 4=1000 to 1 )? ");
        scanf("%d", &guessAlgorithm);  // let user select the algorithm for guessing number.

        // prompt for guess
        puts(
            "I have a number between 1 and 1000.\n"
            "Can you guess my number?\n"
            "Please type your first guess.");

        // loop until correct number
        while (guessResponse != 0) {
            if (guessAlgorithm == 1) {  // binary search
                guess = (ansRange[1] - ansRange[0]) / 2 + ansRange[0];
            } else if (guessAlgorithm == 2) {  // random
                guess = 1 + rand() % 1000;
            } else if (guessAlgorithm == 3) {  // 1 to 1000
                guess = ansRange[0]++;
            } else {  // 1000 to 1
                guess = ansRange[1]--;
            }
            printf("> %d. Bot guess: %d\n", ++count, guess);

            guessResponse = isCorrect(guess, answer);
            if (guessAlgorithm == 1) {  // for binary search
                if (guessResponse == 1) {
                    ansRange[1] = guess;  // guess is too high
                } else if (guessResponse == -1) {
                    ansRange[0] = guess;  // guess is too low
                }
            }
        }

        // prompt for another game
        printTamagotchi();
        printf("\nExcellent! You guessed the number in %d times!\nWould you like to play again?\n", count);
        printf("Please type ( 1=yes, 2=no )? ");
        scanf("%d", &response);
    } while (response == 1);
}  // end function guessGame

// isCorrect returns -1 if guess is too low, 0 if correct, 1 if too high
// if g does not equal a, displays hint
int isCorrect(int g, int a) {
    // guess is correct
    if (g == a)
        return 0;

    // guess is incorrect; display hint
    if (g < a) {
        printf("Too low. Try again.\n");
        return -1;
    } else {
        printf("Too high. Try again.\n");
        return 1;
    }
}  // end function isCorrect

void printTamagotchi(void) {
    // Declare tamagotchi
    char nyaaCat[][120] = {
        "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░",
        "░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░",
        "░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░",
        "░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░",
        "░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░",
        "░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░",
        "░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░",
        "░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░",
        "░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░",
        "░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░",
        "░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░",
        "░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░",
        "░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░",
        "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░",
    };
    char miku[][200] = {
        "                                          ██████              ",
        "            ██▒▒██    ████████████████▓▓████▒▒████            ",
        "          ████▒▒██████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████▒▒██            ",
        "        ██▓▓████▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒████          ",
        "      ██▓▓▒▒▒▒████▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒██        ",
        "      ██▒▒▒▒▒▒██▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒██        ",
        "    ██▓▓▒▒▒▒██▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████        ",
        "    ██▓▓▒▒▒▒▓▓▓▓▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒██        ",
        "  ██▓▓▒▒▒▒▒▒██▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒      ▒▒▒▒▒▒██      ",
        "  ██▓▓▒▒▒▒▒▒██▒▒▒▒▒▒▓▓▒▒    ░░▒▒░░  ▒▒  ▓▓▒▒▒▒▒▒▒▒▒▒▒▒██      ",
        "  ██▓▓▒▒▒▒▒▒██▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▓▓  ▓▓▓▓▒▒▒▒▓▓▒▒▒▒██      ",
        "  ██▓▓▒▒▒▒▒▒██▒▒▒▒██▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒    ░░▓▓▒▒▒▒▒▒▓▓▒▒██      ",
        "  ██▓▓▒▒▒▒▒▒██▒▒▒▒██▒▒▒▒▒▒▓▓    ▒▒▓▓        ▒▒▒▒▒▒██▒▒██      ",
        "  ██▓▓▒▒▒▒▒▒██▒▒████▒▒▒▒▒▒      ▓▓    ▒▒████▓▓▒▒▒▒████        ",
        "  ██▓▓▒▒▒▒▒▒██▒▒████▓▓▓▓██████  ▓▓      ▓▓░░▓▓▒▒▒▒██          ",
        "  ██▓▓▒▒▒▒▒▒████████▒▒  ░░  ▓▓        ▒▒▒▒  ▓▓▒▒██  ████  ████",
        "  ██▒▒▒▒▒▒▒▒████▒▒██▒▒    ▓▓▒▒        ▓▓▓▓  ▓▓▒▒████▒▒████▒▒██",
        "  ██▒▒▒▒▒▒▒▒██  ████░░    ▓▓▒▒        ░░░░  ▓▓██▓▓██▒▒██▒▒▒▒██",
        "  ██▒▒▒▒▒▒▒▒██    ██      ░░░░            ▓▓██▓▓▒▒██▒▒▒▒▒▒██  ",
        "  ██▒▒▒▒▒▒▒▒██      ████                ████▒▒▒▒▓▓██▒▒▒▒██    ",
        "  ██▒▒▒▒▒▒▒▒▒▒██        ██░░░░░░░░░░▓▓░░  ██▒▒▒▒██  ▒▒██      ",
        "  ██▒▒▒▒▒▒▒▒▓▓██      ██░░  ░░░░░░░░▒▒░░██▓▓████    ██        ",
        "  ██▒▒▒▒▒▒▒▒▓▓██    ██▓▓░░▓▓░░░░░░░░▒▒░░██████    ▓▓██        ",
        "  ██▒▒▒▒▒▒▒▒▒▒██  ████████▒▒▓▓░░░░▒▒██▒▒░░██    ██▒▒▓▓▓▓      ",
        "  ██▒▒▒▒▒▒▒▒▒▒▓▓██████████████▒▒▓▓██████▒▒██  ██▒▒▒▒▓▓██      ",
        "    ██▒▒▒▒▒▒▒▒▓▓████  ████████████████████▓▓▓▓▒▒▒▒▒▒▓▓██      ",
        "    ██▓▓▒▒▒▒▒▒▓▓██  ████▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓████▒▒▒▒▒▒▓▓██      ",
        "      ██▒▒▒▒▒▒▓▓██      ██████████████████    ██▓▓▓▓██        ",
        "        ██▓▓▓▓██        ██▓▓██      ██▓▓██      ████          ",
        "          ████            ████        ████                    ",
    };
    char naruto[][200] = {
        "                                                                ",
        "                                          ▒▒      ▒▒            ",
        "                                          ▒▒▒▒    ▒▒▒▒          ",
        "                                        ▒▒  ░░▒▒▒▒  ▒▒▒▒  ▒▒    ",
        "                                ▒▒▒▒▒▒▒▒▒▒    ░░▒▒  ░░▒▒▒▒▒▒    ",
        "                                  ▒▒░░  ▒▒░░  ░░░░    ▒▒░░▒▒  ▒▒",
        "                                    ▒▒░░        ░░░░  ░░░░▒▒▒▒▒▒",
        "                                ▒▒▒▒▒▒░░░░      ░░░░░░░░▒▒▒▒░░▒▒",
        "                                  ▒▒░░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒  ▒▒",
        "                        ██████████▓▓▓▓▓▓▒▒▒▒▒▒▓▓▒▒    ▒▒▒▒▓▓▒▒▒▒",
        "                  ██████░░░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒    ▒▒  ▒▒▓▓▒▒",
        "                ██▒▒░░░░██▒▒▒▒▒▒▒▒▒▒▓▓▒▒  ▓▓▓▓▓▓▓▓▓▓▓▓▒▒    ▓▓  ",
        "                ████▒▒░░░░▒▒▓▓▓▓▒▒▒▒▒▒  ▒▒░░▒▒  ██▒▒░░▓▓▓▓▓▓▓▓  ",
        "              ▒▒  ░░██▒▒░░██▒▒▓▓▒▒░░██░░▒▒  ░░  ▒▒░░  ░░░░██    ",
        "            ▒▒  ▒▒██░░▒▒▒▒████▒▒▒▒██  ████░░            ░░██    ",
        "          ▒▒░░▒▒▒▒▒▒▒▒░░▒▒▒▒  ██▒▒██    ██▒▒        ░░▒▒░░██    ",
        "          ▒▒▒▒        ▒▒▒▒▒▒    ██▒▒  ▒▒▒▒██▒▒░░▒▒    ░░██      ",
        "        ▒▒▒▒            ▒▒▒▒    ██▒▒▒▒▒▒░░▒▒██▒▒░░░░░░██        ",
        "        ▒▒▒▒              ▒▒  ████▒▒██░░▒▒  ▒▒██████████        ",
        "      ▒▒  ▒▒    ▒▒▒▒        ▒▒██▒▒▒▒░░▒▒▒▒▒▒        ▒▒██        ",
        "      ▒▒  ▒▒  ▒▒    ▒▒      ▒▒▓▓██▒▒▒▒██▒▒██▒▒▒▒▒▒▓▓▒▒██        ",
        "      ▒▒  ▒▒▒▒▒▒    ▒▒      ▒▒████████▒▒██░░▒▒▒▒▒▒▓▓██          ",
        "      ▒▒  ▒▒▒▒▒▒▒▒▒▒        ▒▒██░░██▓▓██░░░░▒▒▒▒  ▒▒██          ",
        "        ▒▒▒▒▒▒▒▒          ▒▒  ██░░░░██▒▒░░░░▒▒    ██            ",
        "        ▒▒▒▒▒▒▒▒        ▒▒▒▒  ██░░░░▒▒▒▒▓▓░░░░▒▒██              ",
        "          ▒▒▒▒▒▒      ▒▒▒▒██▒▒░░░░▒▒░░░░░░▒▒██████              ",
        "            ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░▒▒░░░░▒▒▒▒██▒▒░░▒▒██            ",
        "            ▒▒▒▒▒▒░░    ▒▒██▒▒▒▒██▒▒▒▒▒▒██▒▒░░░░░░▒▒██          ",
        "            ██▒▒░░░░░░░░  ▒▒██████████████▒▒▒▒░░░░░░▒▒██        ",
        "      ██████░░▒▒▒▒░░░░░░▒▒▒▒████    ████████▒▒▒▒░░░░░░██        ",
        "    ██▒▒░░░░░░▒▒▒▒▒▒▒▒▒▒████        ██▒▒██▒▒████░░░░░░██        ",
        "░░██░░██░░▒▒▒▒▒▒▒▒▒▒▒▒██          ████▒▒██▒▒▒▒▒▒▒▒▒▒▒▒██        ",
        "░░██░░██▒▒▒▒▒▒▒▒▒▒████          ██▓▓██▒▒▒▒██▒▒▒▒▒▒▒▒██          ",
        "░░██▒▒░░████▒▒▒▒██              ██▒▒▓▓██▒▒▒▒████████            ",
        "  ████▒▒░░▒▒████                ██▒▒▓▓▓▓████████                ",
        "    ▓▓██████░░░░░░              ██▓▓▒▒▒▒██  ░░░░░░              ",
        "      ▒▒░░░░░░░░░░░░░░░░░░░░░░░░██▓▓▓▓▓▓██░░░░░░░░░░░░░░░░      ",
        "          ░░░░░░░░░░░░░░░░░░░░░░██▓▓▓▓██░░░░░░░░░░░░░░░░        ",
        "                ░░░░░░░░░░░░░░░░██    ██░░░░░░░░░░              ",
        "                    ░░░░░░░░░░░░░░████░░░░░░░░                  ",
    };

    switch (rand() % 3)  // print randomize tamagotchi
    {
        case 0:
            for (int i = 0; i < 14; i++) {
                printf("%s\n", nyaaCat[i]);
            }
            break;
        case 1:
            for (int i = 0; i < 30; i++) {
                printf("%s\n", miku[i]);
            }
            break;
        case 2:
            for (int i = 0; i < 40; i++) {
                printf("%s\n", naruto[i]);
            }
            break;
    }
}