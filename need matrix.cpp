#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int allocation[MAX_PROCESSES][MAX_RESOURCES] = {
    {1, 1, 2},
    {2, 1, 2},
    {3, 0, 1},
    {0, 2, 0},
    {1, 1, 2}
};

int max[MAX_PROCESSES][MAX_RESOURCES] = {
    {5, 4, 4},
    {4, 3, 3},
    {9, 1, 3},
    {8, 6, 4},
    {2, 2, 3}
};

int need[MAX_PROCESSES][MAX_RESOURCES];

void calculateNeed() {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void printMatrix(int matrix[][MAX_RESOURCES], char *name) {
    printf("%s Matrix:\n", name);
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("P%d:\t", i);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    calculateNeed();
    printMatrix(allocation, "Allocation");
    printMatrix(max, "Max");
    printMatrix(need, "Need");

    return 0;
}

