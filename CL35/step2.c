#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    char command[1024];

    while (1) {
        printf("myshell> ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        // Skip empty commands
        if (command[0] == '\0') {
            continue;
        }

        // Create a child process
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            continue;
        }

        if (pid == 0) {
            // Child process

            char* args[] = {command, NULL};

            execvp(command, args);

            // Only reached if execvp fails
            perror("execvp");
            _exit(1);
        }

        // Parent process
        waitpid(pid, NULL, 0);
    }

    return 0;
}
