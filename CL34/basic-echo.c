#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    printf("Starting program\n");
    fflush(stdout);
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child: Before execvp\n");
        fflush(stdout);
        char* args[] = {"echo", "Hello from echo!", NULL};
        execvp("echo", args);

        printf("Child: After execvp\n");
        _exit(1);
    }

    // Parent process
    waitpid(pid, NULL, 0);
    printf("Parent: Child finished\n");

    return 0;
}
