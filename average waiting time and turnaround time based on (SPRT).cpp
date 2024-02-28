#include <stdio.h>

struct Process {
    char pid[3];
    int arrival_time;
    int burst_time;
    int remaining_time;
    int finish_time;
    int waiting_time;
    int turnaround_time;
};

void SRPT(struct Process processes[], int n) {
    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < n) {
        struct Process *shortest_process = NULL;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (shortest_process == NULL || processes[i].remaining_time < shortest_process->remaining_time) {
                    shortest_process = &processes[i];
                }
            }
        }

        if (shortest_process == NULL) {
            current_time++;
            continue;
        }

        shortest_process->remaining_time--;

        if (shortest_process->remaining_time == 0) {
            completed_processes++;
            shortest_process->finish_time = current_time + 1;
            shortest_process->turnaround_time = shortest_process->finish_time - shortest_process->arrival_time;
            shortest_process->waiting_time = shortest_process->turnaround_time - shortest_process->burst_time;
        }

        current_time++;
    }
}

int main() {
    struct Process processes[] = {
        {"P1", 0, 5, 0, 0, 0, 0},
        {"P2", 1, 3, 0, 0, 0, 0},
        {"P3", 2, 3, 0, 0, 0, 0},
        {"P4", 4, 1, 0, 0, 0, 0}
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    SRPT(processes, n);

    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}


