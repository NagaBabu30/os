#include <stdio.h>
#include <stdlib.h>

#define MAX_TRACKS 100

int SCAN(int tracks[], int n, int head) {
    int total_movement = 0;
    int direction = 1;

    while (1) {
        int next_track = -1, min_distance = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if ((tracks[i] - head) * direction >= 0 && abs(tracks[i] - head) < min_distance) {
                next_track = i;
                min_distance = abs(tracks[i] - head);
            }
        }

        if (next_track == -1) {
            direction *= -1;
            continue;
        }

        total_movement += min_distance;
        head = tracks[next_track];
        tracks[next_track] = -1;
        if (++total_movement == n) break;
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

    int total_head_movement = SCAN(tracks, n, head);
    printf("Total head movement: %d\n", total_head_movement);
    printf("Average head movement: %.2f\n", (float)total_head_movement / n);
    return 0;
}

