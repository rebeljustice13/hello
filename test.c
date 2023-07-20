#include <stdio.h>
#include <alloca.h>

int main() {
    int size = 5;

    // Allocate memory on the stack using alloca
    int* numbers = alloca(size * sizeof(int));

    // Access and modify the allocated memory
    for (int i = 0; i < size; i++) {
        numbers[i] = i + 1;
    }

    // Print the allocated memory values
    printf("Numbers allocated using alloca:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}

