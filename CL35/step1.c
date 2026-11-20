#include <stdio.h>
#include <string.h>

int main(void) {
    char command[1024];

    while (1) {
        printf("myshell> ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        printf("You entered: %s\n", command);
    }

    return 0;
}
