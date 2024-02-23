#include <stdio.h>

int main() {
    int n, bt, wt = 0, tat = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time for each process:\n");
    for (int i = 1; i <= n; i++) {
        printf("P%d: ", i);
        scanf("%d", &bt);
        tat += wt + bt;
        avg_wt += wt;
        avg_tat += tat;
        wt += bt;
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("Average Waiting Time = %.2f\n", avg_wt);
    printf("Average Turnaround Time = %.2f\n", avg_tat);

    return 0;
}

