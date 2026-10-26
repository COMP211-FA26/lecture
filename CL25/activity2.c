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

    // Step 2: Allocate memory for the name.

    // Step 3: Check whether malloc() succeeded.
    // Return 0 if allocation failed.

    // Step 4: Copy the name into the allocated memory.

    // Step 5: Initialize the remaining fields.

    // Step 6: Return 1 to indicate success.
}

/*
 * CODE-ALONG 7: Write a function that frees the dynamically
 * allocated memory used to store a Drink's name.
 * Do not free the Drink struct itself.
 */
void free_drink(Drink* drink) {
    // Step 1: Free the dynamically allocated name.

    // Step 2: Set the pointer to NULL to avoid a dangling pointer.
}

int main(void) {
    Drink latte;

    latte.price = 4.50;
    latte.is_iced = 0;

    // CODE-ALONG 1:
    // Allocate enough memory to store
    // the string "Latte", including '\0'.

    // CODE-ALONG 2:
    // Check whether malloc() succeeded.

    // CODE-ALONG 3:
    // Copy "Latte" into the allocated memory.

    // CODE-ALONG 4:
    // Print the drink's name and price.

    // CODE-ALONG 5:
    // Free the dynamically allocated memory.

    // CODE-ALONG 6:
    // Declare a new Drink and initialize it using
    // initialize_drink().

    // Print the new drink.

    // CODE-ALONG 7:
    // Free the dynamically allocated name using free_drink().

    return 0;
}