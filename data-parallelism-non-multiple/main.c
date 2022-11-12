/**
 * T = num of threads
 * N = num of elements
 * chunk = N/T + 1
 * chunk_last = N % chunk
 *
 * This program splits an array in T chunks accordingly with data-parallelism model
 * considering that N is not multiple of T
 */


#include <stdio.h>
#include <pthread.h>

#define T 4
#define N 21

int arr[N];
const int chunk = N / T + 1;

const int chunk_last = N % chunk;

void *pthreads_fn(void *args) {

    int thread_id = (int) args;
    int min = thread_id * chunk;
    int max = chunk + min;
    for (int i = min; i < max; i++) {
        printf("myid = %d, chunk = %d\n", i, chunk);
        arr[i] = i * 2;
    }
    return NULL;
}

void last_chunk(int thread_id) {
    int min = thread_id * chunk;
    int max = chunk_last + min;
    for (int i = min; i < max; i++) {
        printf("myid = %d, chunk = %d\n", i, chunk_last);
        arr[i] = i * 2;
    }
}

void print() {
    for (int i = 0; i < N; i++) {
        printf("arr[%d] is\t%d\n ", i, arr[i]);
    }
}

int main() {

    pthread_t mythreads[T];
    pthread_attr_t myattr;
    void *returnvalue;

    for (int i = 0; i < T - 1; i++) {   // ==> FORK

        pthread_attr_init(&myattr);
        pthread_create(&mythreads[i], &myattr, pthreads_fn, (void *) i);
        pthread_attr_destroy(&myattr);
    }

    last_chunk(T - 1);

    for (int i = 0; i < T - 1; i++) {   // <== JOIN
        pthread_join(mythreads[i], &returnvalue);
    }

    print();

    return 0;
}
