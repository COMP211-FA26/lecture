
#include <stdio.h>
#include <stdlib.h>

// 1. Memory leak
void memory_leak(void) {
    int* arr = malloc(10 * sizeof(int));

    arr[0] = 42;

    // Forgot to free the allocated memory
}

// 2. Invalid read (out-of-bounds)
void invalid_read(void) {
    int* arr = malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }

    printf("%d\n", arr[5]);  // Invalid read

    free(arr);
}

// 3. Invalid write (out-of-bounds)
void invalid_write(void) {
    int* arr = malloc(5 * sizeof(int));

    for (int i = 0; i <= 5; i++) {
        arr[i] = i;  // Invalid write when i == 5
    }

    free(arr);
}

// 4. Use-after-free
void use_after_free(void) {
    int* p = malloc(sizeof(int));

    *p = 42;
    free(p);

    printf("%d\n", *p);  // Accessing freed memory
}

// 5. Double free
void double_free(void) {
    int* p = malloc(sizeof(int));

    *p = 42;
    free(p);
    free(p);  // Freeing the same memory twice
}

// 6. Using uninitialized memory
void uninitialized_memory(void) {
    int* p = malloc(sizeof(int));

    if (*p > 10) {  // Using an uninitialized value
        printf("Large number\n");
    }

    free(p);
}

// 7. Incorrect allocation size
void incorrect_allocation(void) {
    int* arr = malloc(10);  // Only 10 bytes allocated

    for (int i = 0; i < 10; i++) {
        arr[i] = i;  // Writes beyond allocated memory
    }

    free(arr);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <error_number>\n", argv[0]);
        return 1;
    }

    int choice = atoi(argv[1]);

    switch (choice) {
        case 1:
            memory_leak();
            break;
        case 2:
            invalid_read();
            break;
        case 3:
            invalid_write();
            break;
        case 4:
            use_after_free();
            break;
        case 5:
            double_free();
            break;
        case 6:
            uninitialized_memory();
            break;
        case 7:
            incorrect_allocation();
            break;
        default:
            printf("Choose an error number from 1 to 7.\n");
            return 1;
    }

    return 0;
}
