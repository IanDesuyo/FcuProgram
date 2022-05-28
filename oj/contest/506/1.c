#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

/** initialize your data structure here. */
Queue* Create() {
    Queue* obj = malloc(sizeof(Queue));
    obj->front = NULL;
    obj->rear = NULL;

    return obj;
}
/** Inserts an element x into the Queue.*/
void EnQueue(Queue* obj, int x) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    if (obj->front == NULL) {
        obj->front = newNode;
    } else {
        obj->rear->next = newNode;
    }
    obj->rear = newNode;
}
/** Deletes an element from the Queue. If the queue is empty, return -1.*/
int DeQueue(Queue* obj) {
    if (obj->front == NULL) {
        return -1;
    } else {
        Node* temp = obj->front;
        int data = temp->data;
        obj->front = temp->next;
        free(temp);

        if (obj->front == NULL) {
            obj->rear = NULL;
        }

        return data;
    }
}
/**Gets the front item from the queue. If the queue is empty, return -1.*/
int GetFront(Queue* obj) {
    if (obj->front == NULL) {
        return -1;
    } else {
        return obj->front->data;
    }
}

bool QueueEmpty(Queue* obj) {
    return obj->front == NULL;
}

void QueuePrint(Queue* obj) {
    Node* temp = obj->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
