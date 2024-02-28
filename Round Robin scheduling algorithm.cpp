#include <stdio.h>

int main() {
    int NOP, quant, wt = 0, tat = 0, at, bt;

    printf("Total number of processes: ");
    scanf("%d", &NOP);

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < NOP; i++) {
        printf("Process[%d]: ", i + 1);
        scanf("%d %d", &at, &bt);
        printf("\t\tBurst Time: %d\tTAT: %d\tWaiting Time: %d\n", bt, bt + wt - at, wt - at);
        wt += bt;
        tat += bt + wt - at;
    }

    printf("\nAverage Turnaround Time: %.2f\n", (float)tat / NOP);
    printf("Average Waiting Time: %.2f\n", (float)wt / NOP);

    return 0;
}

