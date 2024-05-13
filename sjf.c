#include<stdio.h>
#define MAX_PROCESS 10

struct process{
	int processId;
	int burstTime;
};

void swapProcesses(struct process *p1,struct process *p2){
	struct process temp = *p1;
	*p1=*p2;
	*p2=temp;
}

void priorityScheduling(struct process processes[], int n) {
//	using burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                swapProcesses(&processes[j], &processes[j + 1]);
            }
        }
    }
}


int waitingTime[MAX_PROCESS], turnaroundTime[MAX_PROCESS], completionTime[MAX_PROCESS];
float averageWaitingTime = 0, averageTurnaroundTime = 0;

void calculate(struct process processes[], int n){
	completionTime[0] = processes[0].burstTime;
turnaroundTime[0] = completionTime[0];
waitingTime[0] = 0;

    for (int i = 1; i < n; i++) {
        waitingTime[i] = completionTime[i - 1];
        completionTime[i] = waitingTime[i] + processes[i].burstTime;
        turnaroundTime[i] = completionTime[i];
    }

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        averageWaitingTime += waitingTime[i];
        averageTurnaroundTime += turnaroundTime[i];
    }

    // Calculate average waiting time and average turnaround time
    averageWaitingTime /= n;
    averageTurnaroundTime /= n;
	// Calculate waiti ng time, turnaround time, and completion time for each process


    // Print the scheduling results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].processId, processes[i].burstTime, waitingTime[i], turnaroundTime[i]);
    }
    printf("\nAverage Waiting Time: %.2f", averageWaitingTime);
    printf("\nAverage Turnaround Time: %.2f\n", averageTurnaroundTime);

}


int main() {
    int n;
    struct process processes[MAX_PROCESS];
    printf("Enter the number of processes (up to %d): ", MAX_PROCESS);
    scanf("%d", &n);

    if (n > 0 && n <= MAX_PROCESS) {
        printf("Enter process details:\n");
        for (int i = 0; i < n; i++) {
            printf("Process %d\n", i + 1);
            processes[i].processId = i + 1;
            printf("Enter Burst Time: ");
            scanf("%d", &processes[i].burstTime);
        }

        priorityScheduling(processes, n);
        calculate(processes, n);
        
    } else {
        printf("Invalid number of processes. Please try again.\n");
    }

    return 0;
}

