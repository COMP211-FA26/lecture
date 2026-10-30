#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 2
#define BUFFER_SIZE 256

int main(void) {
    char** words = NULL;
    size_t capacity = INITIAL_CAPACITY;
    size_t count = 0;

    char buffer[BUFFER_SIZE];

    /* TODO: Allocate memory for an array of char* pointers with
    INITIAL_CAPACITY elements. Each element will eventually point to a
    dynamically allocated string. */
    words = malloc(capacity * sizeof(char*));

    if (words == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    printf("Enter words (type 'quit' to stop):\n");

    while (fgets(buffer, sizeof(buffer), stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0';  // remove newline

        if (strcmp(buffer, "quit") == 0) break;

        if (count == capacity) {
            capacity *= 2;

            /* TODO: Use realloc to resize the existing array of char* pointers
            to hold the new (doubled) capacity. Do NOT lose the original
            pointer if realloc fails. */
            char** temp = realloc(words, capacity * sizeof(char*));

            if (temp == NULL) {
                fprintf(stderr, "realloc failed\n");
                break;
            }

            words = temp;
        }

        /* TODO: Allocate enough space on the heap to store the buffer string in
            the heap, including space for the null terminator ('\0'). */
        words[count] = malloc(strlen(buffer) + 1);

        if (!words[count]) {
            fprintf(stderr, "malloc failed\n");
            break;
        }

        strcpy(words[count], buffer);
        count++;
    }

    printf("\nYou entered:\n");
    for (size_t i = 0; i < count; i++) {
        printf("%zu: %s\n", i, words[i]);

        /* TODO: Free the dynamically allocated string
        to prevent a memory leak. */
        free(words[i]);
    }

    /* TODO: After freeing each individual string, free the array
    that stores the char* pointers. */
    free(words);

    return 0;
}