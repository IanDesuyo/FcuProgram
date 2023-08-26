#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} Node;

int main() {
    FILE *f = fopen("input.txt", "r");

    char c;
    int num = 0;
    char action = 0;

    Node *left = NULL;
    Node *right = NULL;

    while ((c = fgetc(f)) != EOF) {
        if (c == 'B' || c == 'E') {
            action = c;
            fgetc(f);
        } else if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        } else if (c == 'R') {
            Node *temp;

            // only 2 nodes
            if (left->right == right) {
                left = NULL;
                right = NULL;
            } else {
                if (left != NULL) {
                    if (left->right != NULL) {
                        left->right->left = NULL;
                    }
                    left = left->right;
                }

                if (right != NULL) {
                    if (right->left != NULL) {
                        right->left->right = NULL;
                    }
                    right = right->left;
                }
            }
            fgetc(f);
            // printf("left=%d right=%d\n", left == NULL ? -1 : left->val, right == NULL ? -1 : right->val);
        } else {
            if (left == NULL && right == NULL) {
                Node *new = malloc(sizeof(Node));
                new->val = num;
                new->left = NULL;
                new->right = NULL;
                left = new;
                right = new;
            } else if (action == 'B') {
                Node *new = malloc(sizeof(Node));
                new->val = num;
                new->left = NULL;
                new->right = left;
                left->left = new;
                left = new;
            } else if (action == 'E') {
                Node *new = malloc(sizeof(Node));
                new->val = num;
                new->left = right;
                new->right = NULL;
                right->right = new;
                right = new;
            }

            // printf("left=%d right=%d\n", left == NULL ? -1 : left->val, right == NULL ? -1 : right->val);
            num = 0;
        }
    }

    Node *curr;
    curr = left;
    while (curr != NULL) {
        printf("%d->", curr->val);
        curr = curr->right;
    }
    printf("NULL\n");

    curr = right;
    while (curr != NULL) {
        printf("%d->", curr->val);
        curr = curr->left;
    }
    printf("NULL\n");

    return 0;
}