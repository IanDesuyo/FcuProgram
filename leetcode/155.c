#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} Node;

typedef struct {
    Node* head;
} MinStack;

MinStack* minStackCreate() {
    // initializes the stack object.
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->head = NULL;

    return stack;
}

void minStackPush(MinStack* obj, int val) {
    // pushes the element val onto the stack.
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = obj->head;
    obj->head = node;
}

void minStackPop(MinStack* obj) {
    // removes the element on the top of the stack.
    Node* node = obj->head;
    obj->head = node->next;
    free(node);
}

int minStackTop(MinStack* obj) {
    // gets the top element of the stack.
    return obj->head->val;
}

int minStackGetMin(MinStack* obj) {
    // retrieves the minimum element in the stack.
    Node* node = obj->head;
    int min = node->val;

    while (node->next != NULL) {
        if (node->next->val < min) {
            min = node->next->val;
        }

        node = node->next;
    }

    return min;
}

void minStackFree(MinStack* obj) {
    // frees the memory space allocated for the stack.
    Node* node = obj->head;
    Node* next;

    while (node != NULL) {
        next = node->next;
        free(node);
        node = next;
    }

    free(obj);
}