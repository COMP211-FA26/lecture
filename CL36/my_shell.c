#include <fcntl.h>
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
        // Display the shell prompt.
        printf("myshell> ");
        fflush(stdout);

        // Read a command from the user.
        // Exit the shell if fgets() reaches EOF.
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }

        // Remove the newline character added by fgets().
        command[strcspn(command, "\n")] = '\0';

        // Split the command into arguments using strtok().
        // Each element of args points into the command array.
        char* args[MAX_ARGS];
        int argc = 0;

        char* token = strtok(command, " \t");

        while (token != NULL && argc < MAX_ARGS - 1) {
            args[argc] = token;
            argc++;
            token = strtok(NULL, " \t");
        }

        // If the user entered an empty command,
        // display the prompt again.
        if (argc == 0) {
            continue;
        }

        // execvp() requires a NULL-terminated argument array.
        args[argc] = NULL;

        // ==================================================
        // ACTIVITY 1: Identify output redirection
        // ==================================================

        // TODO 1: Declare a char pointer named output_file
        //         and initialize it to NULL.

        // TODO 2: Search the args array for ">" using strcmp().
        //         If found:
        //         - Store the following argument in output_file.
        //         - Replace ">" with NULL in args.
        //         - Stop searching.
        //
        // Assume ">" appears at most once, is surrounded
        // by spaces, and is followed by a filename.
        // Assume no command arguments follow the filename.

        // TEST ACTIVITY 1:
        // Temporarily uncomment the following code.
        //
        // printf("Output file: %s\n",
        //        output_file == NULL ? "NONE" : output_file);
        //
        // printf("Arguments passed to execvp:\n");
        // for (int i = 0; args[i] != NULL; i++) {
        //     printf("args[%d] = %s\n", i, args[i]);
        // }
        //
        // continue;

        // Create a child process to execute the command.
        // The parent shell remains running.
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            continue;
        }

        if (pid == 0) {
            // CHILD PROCESS

            // ==================================================
            // ACTIVITY 2: Open the output file
            // ==================================================

            // TODO 3: If we need to redirect to stdout:
            //         - Open the file using open().
            //         - Use O_WRONLY | O_CREAT | O_TRUNC.
            //         - Use permissions 0644.
            //         - Store the returned file descriptor
            //           in a variable named fd.
            //         - If open() fails, print an error using
            //           perror() and exit the child with _exit(1).

            // TEST ACTIVITY 2:
            // Temporarily print the returned file descriptor
            // to stderr after a successful open().
            //
            // fprintf(stderr, "Opened file descriptor: %d\n", fd);
            //
            // Verify that the file is created and that its
            // contents are erased if it already exists.
            //
            // At this stage, stdout still goes to the terminal.

            // ==================================================
            // ACTIVITY 3: Redirect stdout
            // ==================================================

            // TODO 4: After successfully opening the file:
            //         - Use dup2() to redirect STDOUT_FILENO
            //           to fd.
            //         - Check whether dup2() failed.
            //           If so, print an error, close fd,
            //           and exit the child with _exit(1).
            //         - Close fd after successful redirection.
            //
            // Keep this code inside the same conditional
            // block as TODO 3, after open() succeeds.

            // Replace the program running in the child
            // with the command requested by the user.
            execvp(args[0], args);

            // execvp() returns only if an error occurs.
            perror("execvp");
            _exit(1);
        }

        // PARENT PROCESS
        // Wait for the child to finish before displaying
        // the next shell prompt.
        if (waitpid(pid, NULL, 0) == -1) {
            perror("waitpid");
        }
    }

    return 0;
}
