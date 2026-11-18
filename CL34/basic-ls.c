#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process
        char* args[] = {"ls", "-l", NULL};
        execvp("ls", args);

        // Only reached if execvp fails
        perror("execvp");
        _exit(1);
    }

    // Parent process
    waitpid(pid, NULL, 0);

    printf("Child process finished.\n");

    return 0;
}
