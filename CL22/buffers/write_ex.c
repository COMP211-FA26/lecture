#include <unistd.h>

int main(void) {
    for (int i = 0; i < 1000; i++) {
        write(STDOUT_FILENO, "A", 1);
    }

    return 0;
}