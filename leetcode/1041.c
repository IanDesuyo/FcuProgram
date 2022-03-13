#include <stdio.h>
#include <string.h>
typedef int bool;

typedef struct cord {
    int x;
    int y;
    int facing;
} Cord;

bool isRobotBounded(char* instructions) {
    Cord cord = {.x = 0, .y = 0, .facing = 0};
    int loop = 0;

    do {
        for (int i = 0, len = strlen(instructions); i < len; i++) {
            switch (instructions[i]) {
                case 'G':  // move forward
                    switch (cord.facing) {
                        case 0:  // north
                            cord.y++;
                            break;
                        case 1:  // east
                            cord.x++;
                            break;
                        case 2:  // south
                            cord.y--;
                            break;
                        case 3:  // west
                            cord.x--;
                            break;
                    }
                    break;

                case 'L':  // turn left
                    if (cord.facing == 0) {
                        cord.facing = 3;
                    } else {
                        cord.facing--;
                    }
                    break;
                case 'R':  // turn right
                    if (cord.facing == 3) {
                        cord.facing = 0;
                    } else {
                        cord.facing++;
                    }
                default:
                    break;
            }
        }
    } while (loop++ < 4 && (cord.x || cord.y));

    return !cord.x && !cord.y;
}

int main() {
    printf("%d", isRobotBounded("GGLLGG"));
    printf("%d", isRobotBounded("GGL"));

    return 0;
}