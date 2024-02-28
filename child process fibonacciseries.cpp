#include <stdio.h>
#include <pthread.h>

#define MAX_NUMBER 20

// Function to print even numbers
void *printEven(void *arg) {
    for (int i = 2; i <= MAX_NUMBER; i += 2) {
        printf("Even Thread: %d\n", i);
    }
    return NULL;
}

// Function to print odd numbers
void *printOdd(void *arg) {
    for (int i = 1; i <= MAX_NUMBER; i += 2) {
        printf("Odd Thread: %d\n", i);
    }
    return NULL;
}

int main() {
    pthread_t evenThread, oddThread;

    // Create even thread
    if (pthread_create(&evenThread, NULL, printEven, NULL) != 0) {
        fprintf(stderr, "Error creating even thread\n");
        return 1;
    }

    // Create odd thread
    if (pthread_create(&oddThread, NULL, printOdd, NULL) != 0) {
        fprintf(stderr, "Error creating odd thread\n");
        return 1;
    }

    // Wait for both threads to finish
    pthread_join(evenThread, NULL);
    pthread_join(oddThread, NULL);

    return 0;
}

