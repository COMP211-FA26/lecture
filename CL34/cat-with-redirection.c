#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    printf("A: Starting program\n");
    fflush(stdout);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("B: Child started\n");
        fflush(stdout);

        // A

        int in = open("input.txt", O_RDONLY);
        int out = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        int err = open("errors.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

        // B
        if (in == -1 || out == -1 || err == -1) {
            perror("open");
            _exit(1);
        }

        dup2(in, STDIN_FILENO);
        dup2(out, STDOUT_FILENO);
        dup2(err, STDERR_FILENO);

        close(in);
        close(out);
        close(err);

        // C

        printf("C: Child after redirection\n");
        fprintf(stderr, "D: An error message\n");
        fflush(stdout);
        fflush(stderr);

        char* args[] = {"cat", NULL};
        execvp("cat", args);

        perror("execvp");
        _exit(1);
    }

    waitpid(pid, NULL, 0);
    printf("E: Parent finished\n");

    return 0;
}