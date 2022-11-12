#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
/**
 * This program shows the synchronization between producer and consumer using semaphore
 */
int a = 0;
sem_t mysemaphore;

void *producer_fn(void *arg) {
    a = 11;
    // POST synchronize the value of "a"
    sem_post(&mysemaphore);
}

void *consumer_fn(void *arg) {
    // WAIT, don't do that until counter it's been incremented
    sem_wait(&mysemaphore);
    printf("a is %d\n", a);
}

int main() {
    pthread_attr_t myattr;
    pthread_t producer, consumer;
    void *returnedvalue;
    int err;

    // Init the semaphore
    sem_init(&mysemaphore, 1, 0);

    // Fork the thread
    pthread_attr_init(&myattr);
    err = pthread_create(&producer, &myattr, producer_fn, NULL);
    pthread_attr_destroy(&myattr);

    pthread_attr_init(&myattr);
    err = pthread_create(&consumer, &myattr, consumer_fn, NULL);
    pthread_attr_destroy(&myattr);

    // Join the thread
    pthread_join(producer, &returnedvalue);
    pthread_join(consumer, &returnedvalue);

    return 0;
}
