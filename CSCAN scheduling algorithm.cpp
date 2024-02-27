#include <stdio.h>
#include <stdlib.h>

// Function to sort an array in ascending order
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the index of the track closest to the head position
int findNearestTrack(int tracks[], int n, int head) {
    int minDiff = abs(tracks[0] - head);
    int index = 0;

    for (int i = 1; i < n; i++) {
        int diff = abs(tracks[i] - head);
        if (diff < minDiff) {
            minDiff = diff;
            index = i;
        }
    }

    return index;
}

// Function to simulate CSCAN disk scheduling algorithm
int cscan(int tracks[], int n, int head) {
    int totalHeadMovement = 0;
    sortArray(tracks, n);

    // Find index of the track closest to the head position
    int index = findNearestTrack(tracks, n, head);

    // Move towards higher tracks
    for (int i = index; i < n; i++) {
        totalHeadMovement += abs(tracks[i] - head);
        head = tracks[i];
    }

    // Move to the highest track
    totalHeadMovement += abs(tracks[n - 1] - tracks[index]);

    // Move towards lower tracks (wrapping around)
    for (int i = 0; i < index; i++) {
        totalHeadMovement += abs(tracks[i] - tracks[n - 1]);
        head = tracks[i];
    }

    return totalHeadMovement;
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int numTracks = sizeof(tracks) / sizeof(tracks[0]);
    int headPosition = 50; // Starting head position

    int totalHeadMovement = cscan(tracks, numTracks, headPosition);

    printf("Total head movement using CSCAN: %d\n", totalHeadMovement);
    printf("Average head movement using CSCAN: %.2f\n", (float)totalHeadMovement / numTracks);

    return 0;
}
                   

