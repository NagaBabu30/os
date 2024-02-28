#include <stdio.h>

#define NUM_PARTITIONS 6

void firstFit(int partitions[], int processes[], int num_processes) {
    int allocation[num_processes];

    for (int i = 0; i < num_processes; i++) {
        allocation[i] = -1;

        for (int j = 0; j < NUM_PARTITIONS; j++) {
            if (partitions[j] >= processes[i]) {
                allocation[i] = j;
                partitions[j] -= processes[i];
                break; // Allocate to the first available partition and break
            }
        }
    }

    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int partitions[NUM_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[] = {150, 400, 200, 500, 100};
    int num_processes = sizeof(processes) / sizeof(processes[0]);

    firstFit(partitions, processes, num_processes);

    return 0;
}

