//  ___________  _______  ___________  _______    __      ________
// ("     _   ")/"     "|("     _   ")/"      \  |" \    /"       )
//  )__/  \\__/(: ______) )__/  \\__/|:        | ||  |  (:   \___/
//     \\_ /    \/    |      \\_ /   |_____/   ) |:  |   \___  \    
//     |.  |    // ___)_     |.  |    //      /  |.  |    __/  \\   
//     \:  |   (:      "|    \:  |   |:  __   \  /\  |\  /" \   :)
//      \__|    \_______)     \__|   |__|  \___)(__\_|_)(_______/   V0.78763548631
//
//
//  By @IanDesuyo

// ========== Game Settings ==========
#define CANVAS_HEIGHT 20  // The height of the canvas, default = 20
#define CANVAS_WIDTH 10   // The width of the canvas, default = 10
#define RENDER_DELAY 100  // The delay between each frame, default = 100
#define FALL_DELAY 500    // The delay between each fall, default = 500
#define LEFT_KEY 0x25     // The key to move left, default = 0x25 (left arrow)
#define RIGHT_KEY 0x27    // The key to move right, default = 0x27 (right arrow)
#define ROTATE_KEY 0x26   // The key to rotate, default = 0x26 (up arrow)
#define DOWN_KEY 0x28     // The key to move down, default = 0x28 (down arrow)
#define FALL_KEY 0x20     // The key to fall, default = 0x20 (spacebar)
// ===================================

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN() system("cls")
#define LEFT_FUNC() GetAsyncKeyState(LEFT_KEY) & 0x8000
#define RIGHT_FUNC() GetAsyncKeyState(RIGHT_KEY) & 0x8000
#define ROTATE_FUNC() GetAsyncKeyState(ROTATE_KEY) & 0x8000
#define DOWN_FUNC() GetAsyncKeyState(DOWN_KEY) & 0x8000
#define FALL_FUNC() GetAsyncKeyState(FALL_KEY) & 0x8000
#define SLEEP(x) Sleep(x)
#elif __APPLE__
#error "Mac OS is not supported :("
#elif __linux__
#error "Linux is not supported :("
#endif

typedef enum color {
    RED = 41,
    GREEN,
    YELLOW,
    BLUE,
    PURPLE,
    CYAN,
    WHITE,
    BLACK = 0,
} Color;

typedef enum shapeid {
    EMPTY = -1,
    I,
    J,
    L,
    O,
    S,
    T,
    Z,
} ShapeId;

typedef struct shape {
    ShapeId shape;
    Color color;
    char rotates[4][4][4];
    int size;
} Shape;

Shape shapes[7] = {
    {.shape = I, .color = CYAN, .size = 4, .rotates = {{{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},  //
                                                       {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}},
                                                       {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}},
                                                       {{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}}}},
    {.shape = J, .color = BLUE, .size = 3, .rotates = {{{1, 0, 0}, {1, 1, 1}, {0, 0, 0}},  //
                                                       {{0, 1, 1}, {0, 1, 0}, {0, 1, 0}},
                                                       {{0, 0, 0}, {1, 1, 1}, {0, 0, 1}},
                                                       {{0, 1, 0}, {0, 1, 0}, {1, 1, 0}}}},
    {.shape = L, .color = YELLOW, .size = 3, .rotates = {{{0, 0, 1}, {1, 1, 1}, {0, 0, 0}},  //
                                                         {{0, 1, 0}, {0, 1, 0}, {0, 1, 1}},
                                                         {{0, 0, 0}, {1, 1, 1}, {1, 0, 0}},
                                                         {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}}}},
    {.shape = O, .color = WHITE, .size = 2, .rotates = {{{1, 1}, {1, 1}},  //
                                                        {{1, 1}, {1, 1}},
                                                        {{1, 1}, {1, 1}},
                                                        {{1, 1}, {1, 1}}}},
    {.shape = S, .color = GREEN, .size = 3, .rotates = {{{0, 1, 1}, {1, 1, 0}, {0, 0, 0}},  //
                                                        {{0, 1, 0}, {0, 1, 1}, {0, 0, 1}},
                                                        {{0, 0, 0}, {0, 1, 1}, {1, 1, 0}},
                                                        {{1, 0, 0}, {1, 1, 0}, {0, 1, 0}}}},
    {.shape = T, .color = PURPLE, .size = 3, .rotates = {{{0, 1, 0}, {1, 1, 1}, {0, 0, 0}},  //
                                                         {{0, 1, 0}, {0, 1, 1}, {0, 1, 0}},
                                                         {{0, 0, 0}, {1, 1, 1}, {0, 1, 0}},
                                                         {{0, 1, 0}, {1, 1, 0}, {0, 1, 0}}}},
    {.shape = Z, .color = RED, .size = 3, .rotates = {{{1, 1, 0}, {0, 1, 1}, {0, 0, 0}},  //
                                                      {{0, 0, 1}, {0, 1, 1}, {0, 1, 0}},
                                                      {{0, 0, 0}, {1, 1, 0}, {0, 1, 1}},
                                                      {{0, 1, 0}, {1, 1, 0}, {1, 0, 0}}}},
};

typedef struct block {
    Color color;
    ShapeId shape;
    bool current;
} Block;

void setBlock(Block *block, Color color, ShapeId shape, bool current) {
    block->color = color;
    block->shape = shape;
    block->current = current;
}

void resetBlock(Block *block) {
    block->color = BLACK;
    block->shape = EMPTY;
    block->current = false;
}

bool move(int height, int width, Block canvas[height][width], int originalX, int originalY, int originalRotate, int newX, int newY, int newRotate, ShapeId shapeId) {
    Shape shapeData = shapes[shapeId];
    int size = shapeData.size;

    // check if the new position is valid to place the block
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (shapeData.rotates[newRotate][i][j]) {
                if (newX + j < 0 || newX + j >= width || newY + i < 0 || newY + i >= height) {
                    return false;
                }
                if (!canvas[newY + i][newX + j].current && canvas[newY + i][newX + j].shape != EMPTY) {
                    return false;
                }
            }
        }
    }

    // remove the old position
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (shapeData.rotates[originalRotate][i][j]) {
                resetBlock(&canvas[originalY + i][originalX + j]);
            }
        }
    }

    // move the block
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (shapeData.rotates[newRotate][i][j]) {
                setBlock(&canvas[newY + i][newX + j], shapeData.color, shapeId, true);
            }
        }
    }

    return true;
}

int clearLine(int height, int width, Block canvas[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (canvas[i][j].current) {
                canvas[i][j].current = false;
            }
        }
    }
    int linesCleared = 0;

    for (int i = height - 1, isFull = true; i >= 0; isFull = true) {
        for (int j = 0; j < width; j++) {
            if (canvas[i][j].shape == EMPTY) {
                isFull = false;
                break;
            }
        }

        if (isFull) {
            linesCleared++;

            for (int j = 0; j < width; j++) {
                resetBlock(&canvas[i][j]);
            }

            for (int k = i; k > 0; k--) {
                for (int j = 0; j < width; j++) {
                    setBlock(&canvas[k][j], canvas[k - 1][j].color, canvas[k - 1][j].shape, false);
                    resetBlock(&canvas[k - 1][j]);
                }
            }
        } else {
            i--;
        }
    }

    return linesCleared;
}

typedef struct {
    int x;
    int y;
    int score;
    int rotate;
    int fallTime;
    ShapeId queue[4];
} State;

void printCanvas(Block canvas[CANVAS_HEIGHT][CANVAS_WIDTH], State *state) {
    printf("\033[0;0H\n");
    for (int i = 0; i < CANVAS_HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < CANVAS_WIDTH; j++) {
            printf("\x1b[%dm\u3000", canvas[i][j].color);
        }
        printf("\x1b[0m|\n");
    }

    // print next block
    Shape shapeData = shapes[state->queue[1]];
    printf("\033[%d;%dHNext:", 3, CANVAS_WIDTH * 2 + 5);
    for (int i = 1; i <= 4; i++) {
        shapeData = shapes[state->queue[i]];
        for (int j = 0; j < 4; j++) {
            printf("\033[%d;%dH", i * 4 + j, CANVAS_WIDTH * 2 + 15);
            for (int k = 0; k < 4; k++) {
                if (j < shapeData.size && k < shapeData.size && shapeData.rotates[0][j][k]) {
                    printf("\x1b[%dm  ", shapeData.color);
                } else {
                    printf("\x1b[0m  ");
                }
            }
        }
    }

    printf("\033[%d;%dHScore: %10d\n", CANVAS_HEIGHT, CANVAS_WIDTH * 2 + 5, state->score);
}

void logic(Block canvas[CANVAS_HEIGHT][CANVAS_WIDTH], State *state) {
    if (ROTATE_FUNC()) {
        int newRotate = (state->rotate + 1) % 4;
        if (move(CANVAS_HEIGHT, CANVAS_WIDTH, canvas, state->x, state->y, state->rotate, state->x, state->y, newRotate, state->queue[0])) {
            state->rotate = newRotate;
        }
    } else if (LEFT_FUNC()) {
        if (move(CANVAS_HEIGHT, CANVAS_WIDTH, canvas, state->x, state->y, state->rotate, state->x - 1, state->y, state->rotate, state->queue[0])) {
            state->x--;
        }
    } else if (RIGHT_FUNC()) {
        if (move(CANVAS_HEIGHT, CANVAS_WIDTH, canvas, state->x, state->y, state->rotate, state->x + 1, state->y, state->rotate, state->queue[0])) {
            state->x++;
        }
    } else if (DOWN_FUNC()) {
        state->fallTime = FALL_DELAY;
    } else if (FALL_FUNC()) {
        state->fallTime += FALL_DELAY * CANVAS_HEIGHT;
    }

    state->fallTime += RENDER_DELAY;
    while (state->fallTime >= FALL_DELAY) {
        state->fallTime -= FALL_DELAY;

        if (move(CANVAS_HEIGHT, CANVAS_WIDTH, canvas, state->x, state->y, state->rotate, state->x, state->y + 1, state->rotate, state->queue[0])) {
            state->y++;
        } else {
            state->score += clearLine(CANVAS_HEIGHT, CANVAS_WIDTH, canvas) * 100;

            state->x = CANVAS_WIDTH / 2;
            state->y = 0;
            state->rotate = 0;
            state->fallTime = 0;
            state->queue[0] = state->queue[1];
            state->queue[1] = state->queue[2];
            state->queue[2] = state->queue[3];
            state->queue[3] = rand() % 7;

            if (!move(CANVAS_HEIGHT, CANVAS_WIDTH, canvas, state->x, state->y, state->rotate, state->x, state->y, state->rotate, state->queue[0])) {
                printf("\033[%d;%dH\x1b[41m GAME OVER \x1b[0m\033[%d;%dH", CANVAS_HEIGHT - 3, CANVAS_WIDTH * 2 + 5, CANVAS_HEIGHT + 5, 0);
                exit(0);
            }
        }
    }
}

int main() {
    // initialize
    srand(time(NULL));
    State state = {
        .x = CANVAS_WIDTH / 2,
        .y = 0,
        .score = 0,
        .rotate = 0,
        .fallTime = 0,
    };
    Block canvas[CANVAS_HEIGHT][CANVAS_WIDTH];
    for (int i = 0; i < CANVAS_HEIGHT; i++) {
        for (int j = 0; j < CANVAS_WIDTH; j++) {
            resetBlock(&canvas[i][j]);
        }
    }
    for (int i = 0; i < 5; i++) {
        state.queue[i] = rand() % 7;
    }

    CLEAR_SCREEN();
    printf("\e[?25l");

    move(CANVAS_HEIGHT, CANVAS_WIDTH, canvas, state.x, state.y, state.rotate, state.x, state.y, state.rotate, state.queue[0]);

    while (1) {
        logic(canvas, &state);
        printCanvas(canvas, &state);
        SLEEP(RENDER_DELAY);
    }

    return 0;
}