#include <stdio.h>

int main() {
    int n;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time:\n");
    for (int i = 1, bt; i <= n; i++) {
        printf("P%d: ", i);
        scanf("%d", &bt);
        printf("P%d\t%d\t%d\t%d\n", i, bt, avg_wt, bt + avg_wt);
        avg_wt += bt;
        avg_tat += bt + avg_wt;
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("Average Waiting Time= %.2f\n", avg_wt);
    printf("Average Turnaround Time= %.2f\n", avg_tat);

    return 0;
}

