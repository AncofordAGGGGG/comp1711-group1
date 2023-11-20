#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int A[3] [4];
    int B[3] [4];
    int C[3] [4];

    srand(time(NULL));

    initializeArrayRandom(A);
    initializeArrayRandom(B);

    multiplyArrays(A,B,C);

    printf("Array A:\n");printArray(A);

    printf("Array B:\n");printArray(B);

    printf("Array C (result of element-wise multiplication):\n"); printArray(C);

    return 0;
}