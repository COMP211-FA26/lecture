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
 * CODE-ALONG 6: Write a function that initializes a Drink.
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
    size_t num_bytes = strlen(name) + 1;

    // Step 2: Allocate memory for the name.
    drink->name = malloc(num_bytes);

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
 * CODE-ALONG 7: Write a function that frees the dynamically
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
    Drink latte;

    latte.price = 4.50;
    latte.is_iced = 0;

    // CODE-ALONG 1:
    // Allocate enough memory to store
    // the string "Latte", including '\0'.
    latte.name = malloc(strlen("Latte") + 1);

    // CODE-ALONG 2:
    // Check whether malloc() succeeded.
    if (latte.name == NULL) {
        return 1;
    }

    // CODE-ALONG 3:
    // Copy "Latte" into the allocated memory.
    strcpy(latte.name, "Latte");

    // CODE-ALONG 4:
    // Print the drink's name and price.
    printf("%s: $%.2f\n", latte.name, latte.price);

    // CODE-ALONG 5:
    // Free the dynamically allocated memory.
    free(latte.name);
    latte.name = NULL;

    // CODE-ALONG 6:
    // Declare a new Drink and initialize it using
    // initialize_drink().
    Drink mocha;

    if (!initialize_drink(&mocha, "Mocha", 5.00, 1)) {
        printf("Failed to initialize drink.\n");
        return 1;
    }

    // Print the new drink.
    print_drink(&mocha);

    // CODE-ALONG 7:
    // Free the dynamically allocated name using free_drink().
    free_drink(&mocha);

    return 0;
}