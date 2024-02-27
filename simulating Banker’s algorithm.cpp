#include <stdio.h>

#define MAX_PROC 100
#define MAX_RES 100

int alloc[MAX_PROC][MAX_RES], max[MAX_PROC][MAX_RES], avail[MAX_RES], n, m;

void input() {
    printf("Enter the number of processes and resources: ");
    scanf("%d%d", &n, &m);
    printf("Enter the maximum allocation matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    printf("Enter the current allocation matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    printf("Enter the available resources:\n");
    for (int j = 0; j < m; j++)
        scanf("%d", &avail[j]);
}

int isSafe() {
    int finish[MAX_PROC] = {0}, work[MAX_RES];
    for (int i = 0; i < m; i++) 
        work[i] = avail[i];

    int safeSeq[MAX_PROC], count = 0;
    while (count < n) {
        int found = 0;
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[p][j] > work[j])
                        break;
                }
                if (j == m) {
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[p][k];
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }
        if (!found)
            return 0; // System is in unsafe state
    }
    printf("System is in safe state.\nSafe sequence: ");
    for (int i = 0; i < n; i++)
        printf("%d ", safeSeq[i]);
    printf("\n");
    return 1; // System is in safe state
}

int main() {
    input();
    if (!isSafe())
        printf("System is in unsafe state. Deadlock may occur.\n");
    return 0;
}


