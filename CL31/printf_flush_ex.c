#include <stdio.h>

#define NUM_ITERATIONS 100000

int main(void) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        printf("Hello");
        fflush(stdout);
    }
    return 0;
}