#include <stdio.h>
#define PROCESSES 4
#define RESOURCES 3
int main() {
    int claim[PROCESSES][RESOURCES] = {
        {3, 2, 2},
        {6, 1, 3},
        {3, 1, 4},
        {4, 2, 2}
    };
    int allocation[PROCESSES][RESOURCES] = {
        {1, 0, 0},
        {6, 1, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int available[RESOURCES] = {9, 3, 6};
    int finish[PROCESSES] = {0};
    int work[RESOURCES];
    for (int i = 0; i < RESOURCES; i++)
        work[i] = available[i];
    int need[PROCESSES][RESOURCES];
    for (int i = 0; i < PROCESSES; i++) {
        for (int j = 0; j < RESOURCES; j++) {
            need[i][j] = claim[i][j] - allocation[i][j];
        }
    }
    int count = 0;
    while (count < PROCESSES) {
        int found = 0;
        for (int i = 0; i < PROCESSES; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < RESOURCES; j++) {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == RESOURCES) {
                    for (int k = 0; k < RESOURCES; k++) {
                        work[k] += allocation[i][k];
                    }
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (!found)
            break;
    }

    if (count == PROCESSES)
        printf("System is in a safe state\n");
    else
        printf("System is in an unsafe state\n");

    return 0;
}

