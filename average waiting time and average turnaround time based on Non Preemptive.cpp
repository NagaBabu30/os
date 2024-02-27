#include <stdio.h>

int main() {
    int n;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time:\n");
    for (int i = 1, waiting_time = 0; i <= n; i++) {
        int burst_time;
        printf("P%d: ", i);
        scanf("%d", &burst_time);
        int turnaround_time = burst_time + waiting_time;
        printf("P%d\t%d\t%d\t%d\n", i, burst_time, waiting_time, turnaround_time);
        avg_wt += waiting_time;
        avg_tat += turnaround_time;
        waiting_time += burst_time;
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("Average Waiting Time= %.2f\n", avg_wt);
    printf("Average Turnaround Time= %.2f\n", avg_tat);

    return 0;
}

