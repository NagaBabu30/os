#include <stdio.h>
#include <stdlib.h>

#define MAX_TRACKS 100

int LOOK(int tracks[], int n, int head) {
    int total_movement = 0;
    for (int i = 0; i < n; ++i) {
        total_movement += abs(tracks[i] - head);
        head = tracks[i];
    }
    return total_movement;
}

int main() {
    int tracks[MAX_TRACKS], n, head;
    printf("Enter the number of tracks: ");
    scanf("%d", &n);
    printf("Enter the track positions: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &tracks[i]);
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    int total_head_movement = LOOK(tracks, n, head);
    printf("Total head movement: %d\n", total_head_movement);
    printf("Average head movement: %.2f\n", (float)total_head_movement / n);
    return 0;
}

