#include <stdio.h>
#include <stdlib.h>

typedef struct alphabet {
    char ch;
    int count;
} Alphabet;

int compare(const void* a, const void* b) {
    Alphabet aa = *(Alphabet*)a;
    Alphabet ab = *(Alphabet*)b;

    if (aa.count == ab.count) {
        return ab.ch - aa.ch;
    }
    return aa.count - ab.count;
}

int main() {
    char c = 0;
    while (c != EOF) {
        Alphabet alphabets[127];

        for (int i = 0; i < 127; i++) {
            alphabets[i].ch = i;
            alphabets[i].count = 0;
        }

        do {
            if (c >= 32 && c <= 126) {
                alphabets[c].count++;
            }
        } while ((c = getchar()) != '\n');

        qsort(alphabets, 127, sizeof(Alphabet), compare);

        for (int i = 0; i < 127; i++) {
            if (alphabets[i].count) {
                printf("%d %d\n", alphabets[i].ch, alphabets[i].count);
            }
        }
        if ((c = getchar()) != EOF) {
            printf("\n");
        }
    }

    return 0;
}