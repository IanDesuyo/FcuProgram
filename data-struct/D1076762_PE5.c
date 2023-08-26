#include <stdio.h>
#include <stdlib.h>

typedef struct _MinHeap {
    int *data;
    int size;
    int capacity;
} MinHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MinHeap *heap, int index) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int smallest = index;

    if (left < heap->size && heap->data[left] < heap->data[smallest]) {
        smallest = left;
    }

    if (right < heap->size && heap->data[right] < heap->data[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&heap->data[index], &heap->data[smallest]);
        heapify(heap, smallest);
    }
}

void insertHeap(MinHeap *heap, int val) {
    heap->data[heap->size] = val;
    int index = heap->size;
    heap->size++;

    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->data[parent] > heap->data[index]) {
            swap(&heap->data[parent], &heap->data[index]);
            index = parent;
        } else {
            break;
        }
    }
}

int popHeap(MinHeap *heap) {
    int val = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return val;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");

    while (!feof(f)) {
        int totalCost = 0;
        int size;
        int val;
        fscanf(f, "%d", &size);

        MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
        heap->data = (int *)malloc(sizeof(int) * size);
        heap->size = 0;
        heap->capacity = size;

        for (int i = 0; i < size; i++) {
            fscanf(f, "%d", &val);
            insertHeap(heap, val);
        }

        while (heap->size > 1) {
            int mins[2] = {popHeap(heap), popHeap(heap)};
            int sum = mins[0] + mins[1];
            totalCost += sum;
            insertHeap(heap, sum);
        }

        printf("%d\n", totalCost);
    }

    return 0;
}