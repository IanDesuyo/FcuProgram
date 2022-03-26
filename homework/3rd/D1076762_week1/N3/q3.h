#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

int q3(void);
void shuffle(unsigned int (*)[]);
void deal(unsigned int (*)[], const char *[], const char *[]);