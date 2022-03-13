#include <stdbool.h>
#include <stdio.h>
#include <windows.h>
#include <winuser.h>

#define CANVAS 50
#define PLAYERSPOT 5
#define JUMP_LEN 5
#define RENDER_DELAY 100

typedef struct {
    int score;
    bool isJumping;
    int jumpAt;
    int jumps;
    int lastBarrier;
    bool gameOver;
} State;

void print(char *barrier, State *state) {
    system("cls");

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
        for (int i = 0; i < 5; i++) {
            for (int i = 0; i < CANVAS; i++) {
                printf(" ");
            }
            printf("\n");
        }
    }

    // main area
    for (int i = 0; i < PLAYERSPOT; i++) {
        printf(" ");
    }
    if (state->isJumping) {
        printf("\x1B[33mO\x1B[32m");
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
        printf("\x1B[33mO\x1B[32m");
    } else {
        if (barrier[PLAYERSPOT] == 'X') {
            printf("\x1B[31m%c\x1B[32m", barrier[PLAYERSPOT]);
        } else {
            printf("%c", barrier[PLAYERSPOT]);
        }
    }
    // front
    for (int i = PLAYERSPOT + 1; i < CANVAS; i++) {
        if (barrier[i] == 'X') {
            printf("\x1B[31m%c\x1B[32m", barrier[i]);
        } else {
            printf("%c", barrier[i]);
        }
    }
    printf("\x1B[0m\n");
    // status bar
    for (int i = 0; i < CANVAS - 26; i++) {
        printf(" ");
    }
    printf("Jumps: %3d  Score: %6d", state->jumps, state->score);
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

void logic(char *barrier, State *state) {
    if (state->isJumping) {
        if (++state->jumpAt == JUMP_LEN) {
            state->isJumping = false;
        }
    } else if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8000) {
        if (!state->isJumping) {
            state->isJumping = true;
            state->jumpAt = 0;
            state->jumps++;
        }
    }

    if (barrier[PLAYERSPOT] == 'X' && !state->isJumping) {
        state->gameOver = true;
        print(barrier, state);
        exit(0);
    }
    state->score++;
}

int main() {
    State state = {.score = 0, .lastBarrier = 100, .isJumping = false, .jumps = 0, .gameOver = false};
    char barrier[CANVAS];
    for (int i = 0; i < CANVAS; i++) {
        barrier[i] = '_';
    }

    while (1) {
        logic(barrier, &state);
        render(barrier, &state);
        print(barrier, &state);
        Sleep(RENDER_DELAY);
    }
}