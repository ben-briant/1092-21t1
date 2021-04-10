// Adapted from example Computer Systems: A programmer's persective, Bryant, O'Halloron
#include <pthread.h> // for pthread_create, pthread_join
#include <stdio.h>    
#include <stdlib.h> 
#include <semaphore.h>

// count -- the global variable to be incremented by our threads
int count = 0;
sem_t sem;

void *Count(void *a) {
    int i;
    int nIterations = *(int *) a;
    for(i = 0; i < nIterations; i++) {
        // Before we increment the count, wait for the semaphore to become available
        sem_wait(&sem);

        /* START OF CRITICAL SECTION */
        // The critical section is the area of code where a shared resource is being accessed.
        count++;
        /* END OF CRITICAL SECTION */

        // Release the semaphore, and allow another thread to access the critical section
        sem_post(&sem);
    }
    return NULL;
}

int main(int argc, char * argv[]) {
    int nIterations;
    pthread_t tid1, tid2;

    if (argc != 2) {
        fprintf(stderr,"Usage: %s <nIterations>\n",argv[0]);
        exit(1);
    }

    nIterations = atoi(argv[1]);

    // Initialise the semaphore
    // The initial value should be '1', as only one thread is
    // allowed to access the 'critical section' (modify the count) at any time
    if (sem_init(&sem, 0, 1)) {
        perror("sem_init");
        exit(1);
    }

    if(pthread_create(&tid1, NULL, Count, &nIterations)) {
        printf("\n ERROR creating thread 1");
        exit(1);
    }

    if(pthread_create(&tid2, NULL, Count, &nIterations)) {
        printf("\n ERROR creating thread 2");
        exit(1);
    }

    if(pthread_join(tid1, NULL)) {        /* wait for the thread 1 to finish */
        printf("\n ERROR joining thread");
        exit(1);
    }

    if(pthread_join(tid2, NULL)) {       /* wait for the thread 2 to finish */
        printf("\n ERROR joining thread");
        exit(1);
    }

    if (count < 2 * nIterations) 
        printf("BOOM! count is [%d], should be %d\n", count, 2*nIterations);
    else
        printf("OK! count is [%d]\n", count);
    return 0;  
}
