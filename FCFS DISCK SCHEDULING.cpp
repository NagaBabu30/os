#include <stdio.h>
#include <stdlib.h>

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int head = 50; // Initial head position
    int total_head_movement = 0;

    // Calculate total head movement
    for (int i = 0; i < n; i++) {
        total_head_movement += abs(head - tracks[i]);
        head = tracks[i];
    }

    // Calculate average head movement
    float avg_head_movement = (float)total_head_movement / n;

    printf("Total head movement: %d\n", total_head_movement);
    printf("Average head movement: %.2f\n", avg_head_movement);

    return 0;
}

