#include <unistd.h>

#define NUM_ITERATIONS 100000

int main(void) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        write(STDOUT_FILENO, "Hello", 5);
    }
    return 0;
}