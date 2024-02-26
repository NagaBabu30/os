#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 6 // Number of philosophers

sem_t room, chopstick[N];

void *philosopher(void *num) {
    int phil = *(int *)num;
    while (1) {
        sem_wait(&room);
        printf("\nPhilosopher %d has entered room", phil);
        sem_wait(&chopstick[phil]);
        sem_wait(&chopstick[(phil + 1) % N]);
        printf("\nPhilosopher %d is eating", phil);
        sleep(2);
        printf("\nPhilosopher %d has finished eating", phil);
        sem_post(&chopstick[(phil + 1) % N]);
        sem_post(&chopstick[phil]);
        sem_post(&room);
    }
}

int main() {
    pthread_t tid[N];
    sem_init(&room, 0, N - 1);
    for (int i = 0; i < N; i++)
        sem_init(&chopstick[i], 0, 1);

    for (int i = 0; i < N; i++)
        pthread_create(&tid[i], NULL, philosopher, &i);

    for (int i = 0; i < N; i++)
        pthread_join(tid[i], NULL);

    return 0;
}

