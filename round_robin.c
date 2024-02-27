#include <stdio.h>

#define MAX_PROCESS 10

void roundRobinScheduling(int bt[], int n, int quantum) {
    int remainingTime[MAX_PROCESS];
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        remainingTime[i] = bt[i];
    }

    while (1) {
        int allProcessesComplete = 1;

        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                allProcessesComplete = 0;

                if (remainingTime[i] <= quantum) {
                    currentTime += remainingTime[i];
                    remainingTime[i] = 0;
                } else {
                    currentTime += quantum;
                    remainingTime[i] -= quantum;
                }

                printf("Process %d executed for %d units.\n", i + 1, currentTime);
            }
        }

        if (allProcessesComplete) {
            break;
        }
    }
}

int main() {
    int n;
    int bt[MAX_PROCESS];
    int quantum;

    printf("Enter the number of processes (up to %d): ", MAX_PROCESS);
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    roundRobinScheduling(bt, n, quantum);

    return 0;
}
