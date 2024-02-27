#include <stdio.h>
#include <pthread.h>

void *printNumbers(void *arg) {
    int threadID = *(int *)arg;
    for (int i = 1; i <= 5; i++) {
        printf("Thread %d: %d\n", threadID, i);
    }
}

int main() {
    printf("Multi-threaded program:\n");
    pthread_t thread1, thread2;
    int threadID1 = 1, threadID2 = 2;
    pthread_create(&thread1, NULL, printNumbers, &threadID1);
    pthread_create(&thread2, NULL, printNumbers, &threadID2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Program execution completed.\n");
    return 0;
}
