#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANVAS 50
#define PLAYERSPOT 5
#define JUMP_LEN 5
#define RENDER_DELAY 100
#define SHOT_RANGE 3
#define DEV_MODE true

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN() system("cls")
#define JUMP_KEY() GetAsyncKeyState(0x26) & 0x8000
#define JUMP_SPACE() GetAsyncKeyState(0x20) & 0x8000
#define SHOT_KEY() GetAsyncKeyState(0x5A) & 0x8000
#define SLEEP(x) Sleep(x)
#elif __linux__
#error "Linux is not supported :("
#endif

typedef struct {
    int score;
    bool isJumping;
    int jumpAt;
    int jumps;
    int lastBarrier;
    bool gameOver;
    int neoArmstrongCycloneJetArmstrongCannonState;
    int neoArmstrongCycloneJetArmstrongCannonDestoryed;
} State;

void print(char *barrier, State *state) {
    printf("\033[0;0H");

    if (state->gameOver) {
        for (int i = 0; i < 2; i++) {
            for (int i = 0; i < CANVAS; i++) {
                printf(" ");
            }
            printf("\n");
        }

        for (int i = 0; i < CANVAS / 2 - 5; i++) {
            printf(" ");
        }
        printf("\x1B[31mGAME OVER\x1B[0m\n");
        for (int i = 0; i < 2; i++) {
            for (int i = 0; i < CANVAS; i++) {
                printf(" ");
            }
            printf("\n");
        }
    } else {
        // upper area
        // 1
        printf("\n\x1B[33m");
        for (int i = 0; i < CANVAS; i++) {
            printf("%c", " ."[(state->neoArmstrongCycloneJetArmstrongCannonState == 3 && i == PLAYERSPOT + 3) || (state->neoArmstrongCycloneJetArmstrongCannonState == 4 && i == PLAYERSPOT + 5) || (state->neoArmstrongCycloneJetArmstrongCannonState == 5 && i == PLAYERSPOT + 7)]);
        }
        printf("\n");

        // 2
        for (int i = 0; i < CANVAS; i++) {
            printf("%c", " ."[(state->neoArmstrongCycloneJetArmstrongCannonState == 2 && i == PLAYERSPOT + 1) || (state->neoArmstrongCycloneJetArmstrongCannonState == 6 && i == PLAYERSPOT + 9)]);
        }
        printf("\n");
        // 3
        for (int i = 0; i < CANVAS; i++) {
            if (i == PLAYERSPOT && state->neoArmstrongCycloneJetArmstrongCannonState) {
                printf("\x1B[33m∩");
            } else {
                printf("%c", " ."[(state->neoArmstrongCycloneJetArmstrongCannonState == 7 && i == PLAYERSPOT + 11)]);
            }
        }
        printf("\n");
        // 4
        for (int i = 0; i < CANVAS; i++) {
            if (i == PLAYERSPOT && state->neoArmstrongCycloneJetArmstrongCannonState) {
                printf("\x1B[33m║");
            } else {
                printf("%c", " ."[(state->neoArmstrongCycloneJetArmstrongCannonState == 8 && i == PLAYERSPOT + 13)]);
            }
        }
        printf("\n");
    }

    // main area
    for (int i = 0; i < PLAYERSPOT; i++) {
        printf(" ");
    }
    if (state->isJumping) {
        if (state->neoArmstrongCycloneJetArmstrongCannonState) {
            printf("\x1B[33m∞\x1B[32m");
        } else {
            printf("\x1B[33mF\x1B[32m");
        }
    } else if (state->neoArmstrongCycloneJetArmstrongCannonState) {
        printf("\x1B[33m║");
        for (int i = PLAYERSPOT + 1; i < CANVAS; i++) {
            printf("%c", " ."[(state->neoArmstrongCycloneJetArmstrongCannonState == 9 && i == PLAYERSPOT + 15)]);
        }
    } else {
        printf(" ");
    }
    printf("\n");

    // back
    printf("\x1B[32m");
    for (int i = 0; i < PLAYERSPOT; i++) {
        if (barrier[i] == 'X') {
            printf("\x1B[31m%c\x1B[32m", barrier[i]);
        } else {
            printf("%c", barrier[i]);
        }
    }
    // dino
    if (!state->isJumping) {
        if (state->neoArmstrongCycloneJetArmstrongCannonState) {
            printf("\x1B[33m∞\x1B[32m");
        } else {
            printf("\x1B[33mF\x1B[32m");
        }
    } else {
        if (barrier[PLAYERSPOT] == 'X') {
            printf("\x1B[31m%c\x1B[32m", barrier[PLAYERSPOT]);
        } else {
            printf("%c", barrier[PLAYERSPOT]);
        }
    }
    // front
    for (int i = PLAYERSPOT + 1; i < CANVAS; i++) {
        if (state->neoArmstrongCycloneJetArmstrongCannonState == 10 && i >= PLAYERSPOT + 17 - SHOT_RANGE && i <= PLAYERSPOT + 17 + SHOT_RANGE) {
            if (i == PLAYERSPOT + 17 - SHOT_RANGE) {
                printf("\x1B[33m\\");
            } else if (i > PLAYERSPOT + 17 - SHOT_RANGE && i < PLAYERSPOT + 17 + SHOT_RANGE) {
                printf("_");
            } else if (i == PLAYERSPOT + 17 + SHOT_RANGE) {
                printf("/\x1B[32m");
            }
        } else if (barrier[i] == 'X') {
            printf("\x1B[31m%c\x1B[32m", barrier[i]);
        } else {
            printf("%c", barrier[i]);
        }
    }
    printf("\x1B[0m\n");
    // status bar
    for (int i = 0; i < CANVAS - 50; i++) {
        printf(" ");
    }
    printf("Destoryed barriers: %3d  Jumps: %3d  Score: %6d\n", state->neoArmstrongCycloneJetArmstrongCannonDestoryed, state->jumps, state->score);
}

void render(char *barrier, State *state) {
    for (int i = 0; i < CANVAS - 1; i++) {
        barrier[i] = barrier[i + 1];
    }

    char next = '_';
    if (state->lastBarrier > 5) {
        next = "_X"[rand() % 2];
        state->lastBarrier = 0;
    } else {
        state->lastBarrier++;
    }

    barrier[CANVAS - 1] = next;
}

int logic(char *barrier, State *state) {
    if (state->isJumping) {
        if (++state->jumpAt == JUMP_LEN) {
            state->isJumping = false;
        }
    } else if (JUMP_KEY() || JUMP_SPACE()) {
        if (!state->isJumping) {
            state->isJumping = true;
            state->jumpAt = 0;
            state->jumps++;
        }
    }
    if (state->neoArmstrongCycloneJetArmstrongCannonState) {
        state->neoArmstrongCycloneJetArmstrongCannonState++;
        if (state->neoArmstrongCycloneJetArmstrongCannonState == 11) {
            state->neoArmstrongCycloneJetArmstrongCannonState = 0;
            for (int i = PLAYERSPOT + 17 - SHOT_RANGE; i <= PLAYERSPOT + 17 + SHOT_RANGE; i++) {
                if (barrier[i] == 'X') {
                    state->neoArmstrongCycloneJetArmstrongCannonDestoryed++;
                }
                barrier[i] = '_';
            }
        }
    } else if (SHOT_KEY()) {
        state->neoArmstrongCycloneJetArmstrongCannonState++;
    }

    if (barrier[PLAYERSPOT] == 'X' && !state->isJumping && !DEV_MODE) {
        state->gameOver = true;
        print(barrier, state);
        return 1;
    }
    state->score++;

    return 0;
}

int main() {
    State state = {.score = 0, .lastBarrier = 100, .isJumping = false, .jumps = 0, .gameOver = false, .neoArmstrongCycloneJetArmstrongCannonState = 0, .neoArmstrongCycloneJetArmstrongCannonDestoryed = 0};
    char barrier[CANVAS];
    for (int i = 0; i < CANVAS; i++) {
        barrier[i] = '_';
    }
    CLEAR_SCREEN();
    printf("\e[?25l");

    while (1) {
        if (logic(barrier, &state)) {
            break;
        };
        render(barrier, &state);
        print(barrier, &state);
        SLEEP(RENDER_DELAY);
    }
}