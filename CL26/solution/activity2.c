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
 * CODE-ALONG 1: Create a Deep Copy
 *
 * Write a function that creates a deep copy of a Drink.
 *
 * The destination Drink struct has already been declared
 * by the caller. Do NOT allocate memory for the struct itself.
 *
 * Allocate new memory for the name, copy the name,
 * and initialize the remaining fields.
 *
 * Return 1 on success and 0 if memory allocation fails.
 *
 * Assume dest has not been initialized previously.
 * Assume src has been initialized successfully.
 */
int copy_drink(Drink* dest, const Drink* src) {
    // STEP 1: Calculate how many bytes are needed to
    // store src->name, including the null terminator.
    size_t num_bytes = strlen(src->name) + 1;

    // STEP 2: Allocate memory for dest->name.
    dest->name = malloc(num_bytes);

    // STEP 3: Check whether malloc() succeeded.
    // If it failed, return 0.
    if (dest->name == NULL) {
        return 0;
    }

    // STEP 4: Copy the characters from src->name
    // into the newly allocated memory.
    strcpy(dest->name, src->name);

    // STEP 5: Copy the price and is_iced fields
    // from src to dest.
    dest->price = src->price;
    dest->is_iced = src->is_iced;

    // STEP 6: Return 1 to indicate success.
    return 1;
}

/*
 * CODE-ALONG 2: Comparing Drinks
 *
 * Write a function that determines whether two Drinks
 * contain the same information.
 *
 * Two Drinks are equal if:
 * - Their names contain the same characters.
 * - Their prices are equal.
 * - Their is_iced values are equal.
 *
 * Return 1 if the Drinks are equal and 0 otherwise.
 *
 * Assume both Drinks have been initialized successfully.
 */
int is_equal(const Drink* a, const Drink* b) {
    // STEP 1: Compare the names using strcmp().
    // Remember that strcmp() returns 0 when
    // two strings contain the same characters.
    int names_equal = strcmp(a->name, b->name) == 0;

    // STEP 2: Compare the prices.
    int prices_equal = a->price == b->price;

    // STEP 3: Compare the is_iced fields.
    int iced_equal = a->is_iced == b->is_iced;

    // STEP 4: Return 1 if all three comparisons
    // indicate equality. Otherwise, return 0.
    return names_equal && prices_equal && iced_equal;
}

int main(void) {
    // Create and initialize a Drink.
    Drink latte;

    latte.name = malloc(strlen("Latte") + 1);
    if (latte.name == NULL) {
        return 1;
    }

    strcpy(latte.name, "Latte");
    latte.price = 4.50;
    latte.is_iced = 0;

    // Create a shallow copy.
    Drink copy = latte;

    // --------------------------------------------------
    // 1. Print the Drinks
    // --------------------------------------------------

    printf("latte: %s, $%.2f\n", latte.name, latte.price);
    printf("copy:  %s, $%.2f\n", copy.name, copy.price);

    // --------------------------------------------------
    // 2. Modify the Price
    // --------------------------------------------------

    copy.price = 6.00;

    printf("latte.price: %.2f\n", latte.price);
    printf("copy.price:  %.2f\n", copy.price);

    // QUESTION:
    // Did changing copy.price affect latte.price? Why?
    //
    // ANSWER:
    // No. Each struct has its own price field.
    // Struct assignment copies the value of price,
    // so modifying one does not affect the other.

    // --------------------------------------------------
    // 3. Modify the Name
    // --------------------------------------------------

    copy.name[0] = 'P';

    printf("latte.name: %s\n", latte.name);
    printf("copy.name:  %s\n", copy.name);

    // QUESTION:
    // Did changing copy.name affect latte.name? Why?
    //
    // ANSWER:
    // Yes. Both name pointers refer to the same
    // dynamically allocated character array.
    // Changing a character through either pointer
    // changes the shared memory.

    // --------------------------------------------------
    // 4. Examine Pointer Values
    // --------------------------------------------------

    printf("latte.name: %p\n", (void*)latte.name);
    printf("copy.name:  %p\n", (void*)copy.name);

    // QUESTION:
    // What do you notice about the two addresses?
    // How does this explain the behavior in Section 3?
    //
    // ANSWER:
    // The addresses are identical because struct
    // assignment copied the pointer value.
    // Both pointers refer to the same heap allocation.

    // --------------------------------------------------
    // CODE-ALONG 1: Create a Deep Copy
    // --------------------------------------------------

    // Implement copy_drink() above.

    // Declare a new local Drink variable named deep_copy.
    // Do NOT dynamically allocate the struct itself.
    Drink deep_copy;

    // Call copy_drink() to create an independent copy
    // of latte. Check whether the function succeeds.
    //
    // If allocation fails, free any memory already
    // allocated by main() before returning.
    if (!copy_drink(&deep_copy, &latte)) {
        printf("Failed to create deep copy.\n");
        free(latte.name);
        return 1;
    }

    // AT HOME:
    // Print the addresses stored in latte.name,
    // copy.name, and deep_copy.name.
    printf("\nPointer addresses:\n");
    printf("latte.name:     %p\n", (void*)latte.name);
    printf("copy.name:      %p\n", (void*)copy.name);
    printf("deep_copy.name: %p\n", (void*)deep_copy.name);

    // QUESTION:
    // Which pointers refer to the same allocation?
    // Which pointer refers to a separate allocation?
    //
    // ANSWER:
    // latte.name and copy.name refer to the same allocation.
    // deep_copy.name refers to a separate allocation.

    // --------------------------------------------------
    // CODE-ALONG 2: Comparing Drinks
    // --------------------------------------------------

    // Implement is_equal() above.

    // 1. Call is_equal() to compare latte and copy.
    //    Print whether they are equal.
    printf("\nComparing drinks:\n");
    printf("latte and copy equal? %d\n", is_equal(&latte, &copy));

    // 2. Call is_equal() to compare latte and deep_copy.
    //    Print whether they are equal.
    printf("latte and deep_copy equal? %d\n", is_equal(&latte, &deep_copy));

    // QUESTION:
    // Can two Drinks be equal even if their name pointers
    // contain different addresses? Explain.
    //
    // ANSWER:
    // Yes. is_equal() compares the contents of the strings
    // using strcmp(), not the pointer addresses.
    // Two strings can contain identical characters
    // even when stored in different memory locations.

    // --------------------------------------------------
    // AT HOME: Modify the Deep Copy's Name
    // --------------------------------------------------

    // Change deep_copy.name[0] to 'M'.
    // Print the names of all three Drinks.
    deep_copy.name[0] = 'M';

    printf("\nAfter modifying deep_copy.name:\n");
    printf("latte.name:     %s\n", latte.name);
    printf("copy.name:      %s\n", copy.name);
    printf("deep_copy.name: %s\n", deep_copy.name);

    // QUESTION:
    // Did changing deep_copy.name affect the other names?
    // Why or why not?
    //
    // ANSWER:
    // No. deep_copy.name points to its own heap allocation.
    // Modifying its characters does not affect the
    // memory referenced by latte.name and copy.name.

    // Compare latte and deep_copy again using is_equal().
    // Print whether they are equal.
    printf("latte and deep_copy equal? %d\n", is_equal(&latte, &deep_copy));

    // QUESTION:
    // Why did the result change?
    //
    // ANSWER:
    // The names now contain different characters.
    // strcmp() returns a nonzero value, so is_equal()
    // returns 0.

    // Restore deep_copy.name so that its characters
    // match latte.name again.
    deep_copy.name[0] = 'P';

    // --------------------------------------------------
    // AT HOME: Comparing Drinks After Changing the Price
    // --------------------------------------------------

    // Change deep_copy.price to a different value.
    deep_copy.price = 5.50;

    // Compare latte and deep_copy again using is_equal().
    // Print whether they are equal.
    printf("\nAfter modifying deep_copy.price:\n");
    printf("latte and deep_copy equal? %d\n", is_equal(&latte, &deep_copy));

    // QUESTION:
    // Why are the Drinks no longer equal?
    //
    // ANSWER:
    // Although their names and is_iced fields match,
    // their prices are different.
    // All three fields must match for is_equal()
    // to return 1.

    // --------------------------------------------------
    // GROUP ACTIVITY: Freeing Dynamically Allocated Memory
    // --------------------------------------------------

    // Work with your group to answer the following questions
    // BEFORE adding any free() calls.
    //
    // 1. How many Drink structs have we created?
    //
    // ANSWER: 3 (latte, copy, and deep_copy).
    //
    // 2. How many separate heap allocations have we made?
    //
    // ANSWER: 2.
    // One for latte.name and one for deep_copy.name.
    //
    // 3. Which name pointers refer to the same allocation?
    //
    // ANSWER: latte.name and copy.name.
    //
    // 4. What would happen if we called free() on all
    //    three name pointers?
    //
    // ANSWER:
    // We would attempt to free the same allocation twice
    // because latte.name and copy.name point to the same
    // memory. This is a double-free error and causes
    // undefined behavior.
    //
    // 5. Which pointers should we pass to free() to
    //    release all dynamically allocated memory?
    //
    // ANSWER:
    // latte.name and deep_copy.name.
    // Each allocation should be freed exactly once.
    //
    // Once you and your group agree:
    //
    // 6. Add the necessary free() calls below.

    free(latte.name);
    free(deep_copy.name);

    // 7. Compile your program with debugging information:
    //
    //    gcc -g -Wall -Wextra -o activity2 activity2.c
    //
    // 8. Run your program with Valgrind:
    //
    //    valgrind --leak-check=full ./activity2
    //
    // 9. Examine the Valgrind output.
    //    Does it report any memory leaks or errors?
    //    If so, work together to fix them.
    //
    // 10. Run Valgrind again to verify your changes.

    return 0;
}