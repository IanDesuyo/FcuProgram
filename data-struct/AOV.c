#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *type;
    int inputCount;
    int delay;
} Gate;

int main() {
    FILE *fGate = fopen("Gate.txt", "r");
    FILE *fCircuit = fopen("Circuit.txt", "r");

    int gateSize;
    fscanf(fGate, "%d", &gateSize);

    Gate *gates = malloc(sizeof(Gate) * gateSize);
    for (int i = 0; i < gateSize; i++) {
        fscanf(fGate, "%s %d %d", gates[i].type, &gates[i].inputCount, &gates[i].delay);
    }

    int circuitInputCount, circuitOutputCount, circuitGateCount;
    fscanf(fCircuit, "%d %d %d", &circuitInputCount, &circuitOutputCount, &circuitGateCount);



    return 0;
}