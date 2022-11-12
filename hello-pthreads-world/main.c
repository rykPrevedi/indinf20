#include <stdio.h>
#include <pthread.h>

/*
 * In this program pthread is used to show the parallel execution model.
 */

void *my_pthread_fn(void *arg) {
    printf("\t\t\t\tI am the pthread, hello world!\n");
    printf("\t\t\t\tmore stuff from pthread\n");
    printf("\t\t\t\tmore stuff from pthread\n");
    printf("\t\t\t\tmore stuff from pthread\n");
    return NULL;
}

int main() {
    printf("Hello, World from the main thread\n");

    pthread_attr_t myattr;
    pthread_attr_init(&myattr);
    pthread_t mythread;
    int err = pthread_create(&mythread, &myattr, my_pthread_fn, NULL); // ==> FORK

    printf("more stuff from the main task\n");
    printf("more stuff from the main task\n");
    printf("more stuff from the main task\n");

    void *returnedvalue;
    pthread_join(mythread, &returnedvalue); // <== JOIN waiting for pthread

    return 0;
}
