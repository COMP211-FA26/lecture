#include <fcntl.h>
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

        // Open output.txt for writing
        int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

        if (fd == -1) {
            perror("open");
            _exit(1);
        }

        // Redirect stdout to output.txt
        if (dup2(fd, STDOUT_FILENO) == -1) {
            perror("dup2");
            close(fd);
            _exit(1);
        }

        // Close the original file descriptor
        close(fd);

        // Execute ls -l
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