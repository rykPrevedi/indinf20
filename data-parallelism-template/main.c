/**
 * T = num of threads
 * N = num of elements
 * chunk = N/T
 *
 * This program splits an array in T chunks accordingly with data-parallelism model
 */


#include <stdio.h>
#include <pthread.h>

#define T 4
#define N 20

int array[N];
const int chunk = N / T;

void *my_pthread_fn(void *args) {
    int thread_id = (int) args;
    int min = thread_id * chunk;
    int max = min + chunk;

    for (int i = min; i < max; i++) {
        array[i] = i * 2;
    }
    return NULL;
}

void print() {
    for (int i = 0; i < N; i++) {
        printf("arr[%d] is %d\n", i, array[i]);
    }
}

int main() {

    pthread_t mythreads[T];
    pthread_attr_t myattr;
    void *returnedvalue;
    int err;

    for (int i = 0; i < T; i++) {   // ==> FORK
        pthread_attr_init(&myattr);
        pthread_create(&mythreads[i],
                       &myattr,
                       my_pthread_fn,
                       (void *) i);
        pthread_attr_destroy(&myattr);
    }

    for (int i = 0; i < T; i++) {   // <== JOIN
        pthread_join(mythreads[i],
                     &returnedvalue);
    }

    print();

    return 0;
}
