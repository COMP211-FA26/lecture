#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND 1024
#define MAX_ARGS 128

int main(void) {
    char command[MAX_COMMAND];

    while (1) {
        printf("myshell> ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        // TODO 1: Declare an array of MAX_ARGS char pointers named args.
        //         Declare an integer argc and initialize it to 0.

        // TODO 2: Use strtok() to find the first token in command.
        //         Treat spaces as delimiters.

        // TODO 3: Use a loop to store each token in args.
        //         Stop when there are no more tokens or when you have
        //         stored MAX_ARGS - 1 tokens (reserve space for NULL).
        //         Remember to advance to the next token each iteration.

        // TODO 4: If the user entered no tokens, skip to the next prompt.

        // TODO 5: Add a NULL pointer after the final argument.

        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            continue;
        }

        if (pid == 0) {
            // Child process
            // TODO 6: Execute the command using execvp().
            //         The program name is the first element of args.

            // Only reached if execvp fails
            perror("execvp");
            _exit(1);
        }

        // Parent process
        if (waitpid(pid, NULL, 0) == -1) {
            perror("waitpid");
        }
    }

    return 0;
}
