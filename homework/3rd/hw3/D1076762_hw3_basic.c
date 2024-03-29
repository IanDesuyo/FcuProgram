#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int count;
    char **data;
} Words;

int contain(char *word, Words *history) {
    for (int i = 0; i < history->count; i++) {
        if (!strcmp(history->data[i], word)) {
            return 1;
        }
    }
    return 0;
}

Words *readHistory(char *path) {
    FILE *f;
    int lines = 0;
    Words *words = calloc(1, sizeof(Words));

    if ((f = fopen(path, "r")) == NULL) {
        printf("Could not open %d .\n", path);
    }

    // count lines
    for (char c = getc(f); c != EOF; c = getc(f)) {
        if (c == '\n')
            words->count++;
    }
    rewind(f);

    char **data = calloc(words->count, sizeof(char *));

    int correctLines = 0;
    while (!feof(f)) {
        char *temp = calloc(7, sizeof(char));  // 5 alphabets + 1 for \0 and 1 for flag
        fscanf(f, "%*s %*d %5[A-Z]s", temp);

        if (!temp[0]) {
            free(temp);
            continue;
        }

        for (int i = 0; i < 5; i++) {  // to lower
            temp[i] += 32;
        }

        data[correctLines++] = temp;
    }
    words->count = correctLines - 1;
    words->data = data;
    return words;
}

Words *readWords(char *path, Words *filter) {
    FILE *f;
    int lines = 0;
    Words *words = calloc(1, sizeof(Words));

    if ((f = fopen(path, "r")) == NULL) {
        printf("Could not open %d .\n", path);
    }

    // count lines
    for (char c = getc(f); c != EOF; c = getc(f)) {
        if (c == '\n')
            words->count++;
    }
    rewind(f);

    char **data = calloc(words->count, sizeof(char *));

    int correctLines = 0;
    for (int i = 0; i < words->count; i++) {
        char *temp = calloc(5, sizeof(char));
        fscanf(f, "%5c\n", temp);

        if (contain(temp, filter)) {
            free(temp);
        } else {
            data[correctLines++] = temp;
        }
    }

    words->count = correctLines;
    words->data = data;
    return words;
}

void freeAll(Words *words) {
    for (int i = 0; i < words->count; i++) {
        free(words->data[i]);
    }

    free(words);
}

void printWords(Words *words) {
    int i, j;
    for (i = 0, j = 0; i < words->count; i++) {
        if (!(words->data[i][6] == 1)) {
            j++;
            printf("%s%c", words->data[i], "\t\n"[!(j % 10)]);
        }
    }
    if (j % 10) {
        printf("\n");
    }
}

void search(Words *words) {
    char input[7];
    char result[7];
    int alphabetCounter[26][2];
    while (1) {
        printf(" Input: ");
        scanf("%5s", input);
        printf("Result: ");
        scanf("%5s", result);

        if (!strcmp(result, "ggggg")) {
            printf("wow u so good!\n");
            return;
        }

        // reset counter
        int hasY = 0;
        for (int i = 0; i < 26; i++) {
            alphabetCounter[i][0] = 0;  // y
            alphabetCounter[i][1] = 0;  // b
        }
        for (int i = 0; i < 5; i++) {
            if (result[i] == 'y') {
                alphabetCounter[input[i] - 97][0]++;
                hasY = 1;
            } else if (result[i] == 'b') {
                alphabetCounter[input[i] - 97][1]++;
            }
        }

        for (int i = 0, flag = 1; i < words->count; i++, flag = 1) {
            if (words->data[i][6] == 1) {  // check if word is filtered
                continue;
            }

            for (int j = 0; j < 5; j++) {
                if (alphabetCounter[words->data[i][j] - 97][0] == 0  // doesn't contain y
                    && alphabetCounter[words->data[i][j] - 97][1] > 0) {
                    flag = 0;
                    break;
                }
            }

            if (flag && hasY) {
                int alphabets[26] = {0};
                for (int j = 0; j < 5; j++) {
                    alphabets[words->data[i][j] - 97]++;
                    if (result[j] == 'y' && (words->data[i][j] == input[j])) {
                        flag = 0;
                        break;
                    }
                }
                for (int j = 0; j < 26; j++) {
                    if (alphabetCounter[j][0] > alphabets[j]) {
                        flag = 0;
                        break;
                    }
                }
            }

            if (flag) {
                for (int j = 0; j < 5; j++) {
                    if (result[j] == 'b' && (words->data[i][j] == input[j])) {
                        flag = 0;
                        break;
                    } else if (result[j] == 'g' && (words->data[i][j] != input[j])) {
                        flag = 0;
                        break;
                    }
                }
            }

            if (!flag) {
                words->data[i][6] = 1;
            }
        }
        printWords(words);
    }
}
int main() {
    Words *history = readHistory("./history.txt");
    Words *words = readWords("./words.txt", history);

    search(words);

    freeAll(history);
    freeAll(words);

    return 0;
}