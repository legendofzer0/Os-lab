#include <stdio.h>

void printNumbers() {
    for (int i = 1; i <= 5; i++) {
        printf("%d\n", i);
    }
}

int main() {
    printf("Single-threaded program:\n");
    printNumbers();
    printf("Program execution completed.\n");
    return 0;
}
