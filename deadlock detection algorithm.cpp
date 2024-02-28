#include <stdio.h>

#define NUM_PROCESSES 3
#define NUM_RESOURCES 3

void checkDeadlock(int max[][NUM_RESOURCES], int allocation[][NUM_RESOURCES], int available[]) {
    int finish[NUM_PROCESSES] = {0};

    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (finish[i]) continue;
        int canFinish = 1;
        for (int j = 0; j < NUM_RESOURCES; j++) {
            if (max[i][j] - allocation[i][j] > available[j]) {
                canFinish = 0;
                break;
            }
        }
        if (canFinish) {
            finish[i] = 1;
            for (int j = 0; j < NUM_RESOURCES; j++)
                available[j] += allocation[i][j];
            i = -1; // Restart loop to recheck previous processes
        }
    }

    int deadlockedProcesses = 0;
    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (!finish[i]) {
            printf("Process P%d is deadlocked.\n", i + 1);
            deadlockedProcesses++;
        }
    }

    if (deadlockedProcesses == 0) printf("No deadlock detected.\n");
}

int main() {
    int max[NUM_PROCESSES][NUM_RESOURCES] = {{3, 6, 8}, {4, 3, 3}, {3, 4, 4}};
    int allocation[NUM_PROCESSES][NUM_RESOURCES] = {{3, 3, 3}, {2, 0, 3}, {1, 2, 4}};
    int available[NUM_RESOURCES] = {1, 2, 0};

    checkDeadlock(max, allocation, available);

    return 0;
}

