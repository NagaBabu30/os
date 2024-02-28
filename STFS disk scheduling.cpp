#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

int SSTF(int requests[], int n, int head) {
    int total_movement = 0;
    for (int i = 0; i < n; ++i) {
        int min_distance = abs(requests[0] - head);
        int nearest_index = 0;
        for (int j = 1; j < n; ++j) {
            int distance = abs(requests[j] - head);
            if (distance < min_distance) {
                min_distance = distance;
                nearest_index = j;
            }
        }
        total_movement += min_distance;
        head = requests[nearest_index];
        requests[nearest_index] = -1; // Mark the processed request as visited
    }
    return total_movement;
}

int main() {
    int requests[MAX_REQUESTS], n, head;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the requests: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &requests[i]);
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    int total_head_movement = SSTF(requests, n, head);
    printf("Total head movement: %d\n", total_head_movement);
    printf("Average head movement: %.2f\n", (float)total_head_movement / n);
    return 0;
}

