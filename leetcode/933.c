#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    obj->head = NULL;
    obj->tail = NULL;
    obj->size = 0;

    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = t;
    node->next = NULL;

    if (obj->head == NULL) {
        obj->head = node;
        obj->tail = node;
    } else {
        obj->tail->next = node;
        obj->tail = node;
    }

    obj->size++;

    while (obj->head != NULL && obj->head->val + 3000 < t) {
        Node* tmp = obj->head;
        obj->head = obj->head->next;
        free(tmp);
        obj->size--;
    }

    return obj->size;
}

void recentCounterFree(RecentCounter* obj) {
    Node* curr = obj->head;

    while (curr != NULL) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }

    free(obj);
}
