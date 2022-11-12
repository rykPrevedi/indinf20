#include <stdio.h>
#include <pthread.h>

void *pthreads_fn(void *args) {

    int myid = (int) args;
    //unsigned long myid_from_os = pthread_self();
    printf("Hello PThreads world! My id is: %d\n", myid);
}

int main() {
    const unsigned int NUM_THREADS = 16;
    pthread_t mythreads[NUM_THREADS];
    pthread_attr_t myattr;
    void *returnedvalue;
    int err;

    for (int i = 0; i < NUM_THREADS; i++) { // =>FORK
        pthread_attr_init(&myattr);
        err = pthread_create(&mythreads[i], &myattr, pthreads_fn, (void *) i);
    }

    // Now the main (master) thread can execute other useful stuff here
    // while other threads (slave) execute in parallel

    for (int i = 0; i < NUM_THREADS; i++){  // <= JOIN
        pthread_join(mythreads[i], &returnedvalue);
    }

    return 0;
}
