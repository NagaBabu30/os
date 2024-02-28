#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

int CLOOK(int requests[], int n, int head) {
    int total_movement = 0;
    for (int i = 0; i < n; ++i) {
        total_movement += abs(requests[i] - head);
        head = requests[i];
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

    int total_head_movement = CLOOK(requests, n, head);
    printf("Total head movement: %d\n", total_head_movement);
    printf("Average head movement: %.2f\n", (float)total_head_movement / n);
    return 0;
}

