#include <stdio.h>

int main() {
    int n, bt, wt = 0, tat = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int priority[n];

    printf("Enter Burst Time and Priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &bt, &priority[i]);
        tat += bt;
        avg_tat += tat;
    }

    for (int i = 0; i < n; i++) {
        avg_wt += (float)(priority[i] * tat) / n;
    }

    printf("\nAverage Waiting Time = %.2f\n", avg_wt - avg_tat / n);
    printf("Average Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}

