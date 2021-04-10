// This code may result in "deadlock". What is deadlock,
// why does it occur, and how can we fix it?

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int andrews_bank_account1 = 100;
sem_t bank_account1_lock;

int andrews_bank_account2 = 200;
sem_t bank_account2_lock;

// swap values between Andrew's two bank account 100,000 times
void *swap1(void *argument) {
    for (int i = 0; i < 100000; i++) {
        sem_wait(&bank_account1_lock);
        sem_wait(&bank_account2_lock);

        int tmp = andrews_bank_account1;
        andrews_bank_account1 = andrews_bank_account2;
        andrews_bank_account2 = tmp;

        sem_post(&bank_account2_lock);
        sem_post(&bank_account1_lock);

    }

    return NULL;
}

// swap values between Andrew's two bank account 100,000 times
void *swap2(void *argument) {
    for (int i = 0; i < 100000; i++) {
        // Swap the order the semaphores are acquired to match swap1's order
        // Since we acquire semaphores in the same order in both threads,
        // it is impossible to deadlock
        // Thread 2 can't acquire lock 2 without first acquiring lock 1
        // So if a thread has lock 1, it will always be able to get lock 2,
        // and won't deadlock (where one thread has lock 1 and is waiting for lock 2,
        // while the other has lock 2 and is waiting for lock 1)
        sem_wait(&bank_account1_lock);
        sem_wait(&bank_account2_lock);

        int tmp = andrews_bank_account1;
        andrews_bank_account1 = andrews_bank_account2;
        andrews_bank_account2 = tmp;

        sem_post(&bank_account2_lock);
        sem_post(&bank_account1_lock);

    }

    return NULL;
}

int main(void) {
    //create two threads performing almost the same task
    sem_init(&bank_account1_lock, 0, 1);
    sem_init(&bank_account2_lock, 0, 1);
    pthread_t thread_id1;
    pthread_create(&thread_id1, NULL, swap1, NULL);

    pthread_t thread_id2;
    pthread_create(&thread_id2, NULL, swap2, NULL);

    // threads will possibly never finish
    // deadlock will likely occur

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);

    return 0;
}