#include <stdio.h>

typedef struct {
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void fcfs(Process processes[], int n) {
    processes[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

float averageWaitingTime(Process processes[], int n) {
    int total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
    }
    return (float) total_waiting_time / n;
}

float averageTurnaroundTime(Process processes[], int n) {
    int total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_turnaround_time += processes[i].turnaround_time;
    }
    return (float) total_turnaround_time / n;
}

int main() {
    Process processes[] = {
        {2, 0, 0},
        {4, 0, 0},
        {8, 0, 0}
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    fcfs(processes, n);

    printf("Average Waiting Time: %.2f\n", averageWaitingTime(processes, n));
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime(processes, n));

    return 0;
}

