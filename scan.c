#include <stdio.h>
#include <stdlib.h>

int main()
{
    int diskQueue[20]; 
    int diskQueueSize;
    int initialHeadPosition;
    int direction;

    printf("Enter the number of disk requests: ");
    scanf("%d", &diskQueueSize);

    printf("Enter the disk requests: ");
    for (int i = 0; i < diskQueueSize; i++) {
        scanf("%d", &diskQueue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &initialHeadPosition);

    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);


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

    if (direction == 0) { // Left
        for (int i = initialPosition; i >= 0; i--) {
            headMovement += abs(currentHeadPosition - diskQueue[i]);
            currentHeadPosition = diskQueue[i];
        }
        headMovement += currentHeadPosition; // Move to the leftmost track
        currentHeadPosition = 0;
        for (int i = initialPosition + 1; i < diskQueueSize; i++) {
            headMovement += abs(currentHeadPosition - diskQueue[i]);
            currentHeadPosition = diskQueue[i];
        }
    } else { 
        for (int i = initialPosition; i < diskQueueSize; i++) {
            headMovement += abs(currentHeadPosition - diskQueue[i]);
            currentHeadPosition = diskQueue[i];
        }
        headMovement += abs(currentHeadPosition - 99); 
		       currentHeadPosition = 99;
        for (int i = initialPosition - 1; i >= 0; i--) {
            headMovement += abs(currentHeadPosition - diskQueue[i]);
            currentHeadPosition = diskQueue[i];
        }
    }

    printf("Total head movement: %d\n", headMovement);

    return 0;
}
