#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int shared_memory = 0;
sem_t semaphore;

void *double_thread(void *arg) {
    while (1) {
        sem_wait(&semaphore);
        printf("Double: %d\n", shared_memory * 2);
        sem_post(&semaphore);
        pthread_exit(NULL);
    }
}

void *five_times_thread(void *arg) {
    while (1) {
        sem_wait(&semaphore);
        printf("Five times: %d\n", shared_memory * 5);
        sem_post(&semaphore);
        pthread_exit(NULL);
    }
}

int main() {
    pthread_t tid1, tid2;
    sem_init(&semaphore, 0, 1);

    pthread_create(&tid1, NULL, double_thread, NULL);
    pthread_create(&tid2, NULL, five_times_thread, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    sem_destroy(&semaphore);

    return 0;
}

