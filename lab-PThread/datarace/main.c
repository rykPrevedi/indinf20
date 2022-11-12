#include <stdio.h>
#include <pthread.h>

/**
 * This program shows a non-atomic operation with a parallel execution model,
 * the result is totally non predictable because the critical section is not mutually exclusive.
 */

int x;

void *my_pthread_fn(void *arg) {
    /// Critical Section
    x++;
    ///
    return NULL;
}

int main() {

    const int NUMTHREAD = 256;
    pthread_attr_t myattr;
    pthread_t mythread[NUMTHREAD];

    for (int i = 0; i < NUMTHREAD; i++) {
        pthread_attr_init(&myattr);
        int err = pthread_create(&mythread[i], &myattr, my_pthread_fn, NULL);  // => FORK
        pthread_attr_destroy(&myattr);
    }

    void *returnvalue;
    for (int i = 0; i < NUMTHREAD; i++) {
        pthread_join(mythread[i], &returnvalue);   // => JOIN
    }

    printf("x is: %d\n", x);
    return 0;
}
