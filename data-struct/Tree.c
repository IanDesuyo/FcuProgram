#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char val;
    struct node *left;
    struct node *right;
} Node;

int getIndex(char val, char *array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == val) {
            return i;
        }
    }
    return -1;
}

Node *makeTree(char *preOrder, char *inOrder, int size) {
    int i = getIndex(preOrder[0], inOrder, size);

    Node *node = (Node *)malloc(sizeof(Node));
    node->val = preOrder[0];
    node->left = NULL;
    node->right = NULL;

    if (i > 0) {
        node->left = makeTree(preOrder + 1, inOrder, i);
    }

    if (i < size - 1) {
        node->right = makeTree(preOrder + i + 1, inOrder + i + 1, size - i - 1);
    }

    return node;
}

void fprintPostOrder(FILE *f, Node *node) {
    if (node == NULL) {
        return;
    }

    if (node->left != NULL) {
        fprintPostOrder(f, node->left);
    }

    if (node->right != NULL) {
        fprintPostOrder(f, node->right);
    }

    fprintf(f, "%c", node->val);
}

int main() {
    FILE *f = fopen("Input.txt", "r");

    int size;
    fscanf(f, "%d", &size);

    char preOrder[size];
    char inOrder[size];

    fscanf(f, "%s", preOrder);
    fscanf(f, "%s", inOrder);

    Node *root = makeTree(preOrder, inOrder, size);

    FILE *fout = fopen("Output.txt", "w+");
    fprintPostOrder(fout, root);
    return 0;
}