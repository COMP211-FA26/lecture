#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    double price;
    int is_iced;
} Drink;

void print_drink(Drink* drink) {
    printf("%s: $%.2f (%s)\n", drink->name, drink->price,
           drink->is_iced ? "Iced" : "Hot");
}

/*
 * CODE-ALONG 1: Write a function that initializes a Drink.
 * The function should dynamically allocate memory for the name,
 * copy the name, and initialize the remaining fields.
 * Return 1 on success and 0 if memory allocation fails.
 *
 * Assume the Drink has not been initialized previously.
 */
int initialize_drink(Drink* drink, const char name[], double price,
                     int is_iced) {
    // Step 1: Calculate the number of bytes needed for the name,
    // including the null terminator.
    size_t size = strlen(name) + 1;

    // Step 2: Allocate memory for the name.
    drink->name = malloc(size);

    // Step 3: Check whether malloc() succeeded.
    // Return 0 if allocation failed.
    if (drink->name == NULL) {
        return 0;
    }

    // Step 4: Copy the name into the allocated memory.
    strcpy(drink->name, name);

    // Step 5: Initialize the remaining fields.
    drink->price = price;
    drink->is_iced = is_iced;

    // Step 6: Return 1 to indicate success.
    return 1;
}

/*
 * CODE-ALONG 2: Write a function that frees the dynamically
 * allocated memory used to store a Drink's name.
 * Do not free the Drink struct itself.
 */
void free_drink(Drink* drink) {
    // Step 1: Free the dynamically allocated name.
    free(drink->name);

    // Step 2: Set the pointer to NULL to avoid a dangling pointer.
    drink->name = NULL;
}

int main(void) {
    // CODE-ALONG 1:
    // Declare a new Drink and initialize it using
    // initialize_drink().
    // Check whether the function succeeds.
    Drink mocha;

    if (!initialize_drink(&mocha, "Mocha", 5.00, 1)) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Print the new drink.
    print_drink(&mocha);

    // CODE-ALONG 2:
    // Free the dynamically allocated name using free_drink().
    free_drink(&mocha);

    return 0;
}