#include <stdio.h>

int main(void) {
    for (int i = 0; i < 1000; i++) {
        printf("A");
        fflush(stdout);
    }

    return 0;
}