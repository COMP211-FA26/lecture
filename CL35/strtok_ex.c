#include <stdio.h>
#include <string.h>

int main(void) {
    char command[] = "ls -l -a";

    char* token = strtok(command, " ");

    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}