#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void SCAN(int tracks[], int head, int size) {
    int total_head_movement = 0;
    int start = 0, end = size - 1;
    int direction; // 1 for right, 0 for left

    // Find the direction of head movement
    if (head >= (tracks[size - 1] + tracks[0]) / 2)
        direction = 0; // Move left
    else
        direction = 1; // Move right

    printf("Head Movement: %d", head);
    if (direction)
        printf(" ->");
    else
        printf(" <-");

    // Move towards the end
    if (direction) {
        for (int i = head; i <= tracks[end]; ++i) {
            for (int j = start; j <= end; ++j) {
                if (tracks[j] == i) {
                    total_head_movement += abs(i - head);
                    head = i;
                    printf(" %d ->", i);
                    break;
                }
            }
        }
        // Move towards the start
        for (int i = tracks[end]; i >= tracks[start]; --i) {
            for (int j = end; j >= start; --j) {
                if (tracks[j] == i) {
                    total_head_movement += abs(i - head);
                    head = i;
                    printf(" %d ->", i);
                    break;
                }
            }
        }
    } else { // Move towards the start
        for (int i = head; i >= tracks[start]; --i) {
            for (int j = end; j >= start; --j) {
                if (tracks[j] == i) {
                    total_head_movement += abs(i - head);
                    head = i;
                    printf(" %d ->", i);
                    break;
                }
            }
        }
        // Move towards the end
        for (int i = tracks[start]; i <= tracks[end]; ++i) {
            for (int j = start; j <= end; ++j) {
                if (tracks[j] == i) {
                    total_head_movement += abs(i - head);
                    head = i;
                    printf(" %d ->", i);
                    break;
                }
            }
        }
    }

    printf("\nTotal Head Movement: %d\n", total_head_movement);
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
    int size = sizeof(tracks) / sizeof(tracks[0]);
    int head = 55; // Initial head position

    printf("Initial Head Position: %d\n", head);
    SCAN(tracks, head, size);

    return 0;
}

