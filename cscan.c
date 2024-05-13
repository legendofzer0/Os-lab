#include <stdio.h>
#include <stdlib.h>

int main()
{
    int diskQueue[20]; 
    int diskQueueSize;
    int initialHeadPosition;

    printf("Enter the number of disk requests: ");
    scanf("%d", &diskQueueSize);

    printf("Enter the disk requests: ");
    for (int i = 0; i < diskQueueSize; i++) {
        scanf("%d", &diskQueue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &initialHeadPosition);

    for (int i = 0; i < diskQueueSize - 1; i++) {
        for (int j = 0; j < diskQueueSize - i - 1; j++) {
            if (diskQueue[j] > diskQueue[j + 1]) {
                int temp = diskQueue[j];
                diskQueue[j] = diskQueue[j + 1];
                diskQueue[j + 1] = temp;
            }
        }
    }

    int headMovement = 0;
    int currentHeadPosition = initialHeadPosition;

    int initialPosition = 0;
    while (diskQueue[initialPosition] < initialHeadPosition && initialPosition < diskQueueSize) {
        initialPosition++;                                              
    }

    for (int i = initialPosition; i < diskQueueSize; i++) {
        headMovement += abs(currentHeadPosition - diskQueue[i]);
        currentHeadPosition = diskQueue[i];
        printf("Current head position: %d\n", currentHeadPosition);
    }
    headMovement += abs(currentHeadPosition - 99); 
	currentHeadPosition = 0;   
    for (int i = 0; i < initialPosition; i++) {
        headMovement += abs(currentHeadPosition - diskQueue[i]);
        currentHeadPosition = diskQueue[i];
        printf("Current head position: %d\n", currentHeadPosition);
    }
    

    printf("Total head movement: %d\n", headMovement);

    return 0;
}
