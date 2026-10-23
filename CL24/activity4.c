
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    double price;
    int is_iced;  // 0 = hot, 1 = iced
} Drink;

// Print a drink's information.
void print_drink(Drink* drink) {
    printf("%s: $%.2f (%s)\n", drink->name, drink->price,
           drink->is_iced ? "Iced" : "Hot");
}

// Increase a drink's price.
void increase_price(Drink* drink, double amount) { drink->price += amount; }

// Change a drink to hot.
void make_hot(Drink* drink) { drink->is_iced = 0; }

// =====================================
// CODE-ALONG: CREATE A DRINK FUNCTION
// =====================================

// TODO 6: Complete this function.
// 1. Allocate memory for a Drink.
// 2. Check if malloc() returned NULL.
// 3. Copy name using strcpy().
// 4. Set price and is_iced.
// 5. Return the pointer.
//
// Assume the name fits in the array.
Drink* create_drink(const char name[], double price, int is_iced) {
    return NULL;  // Replace during code-along.
}

int main(void) {
    // =====================================
    // PART 1: ALLOCATING MEMORY
    // =====================================

    printf("\n=====================================\n");
    printf("   PART 1: ALLOCATING MEMORY\n");
    printf("=====================================\n");

    // TODO 1: Declare a Drink pointer called latte.

    // TODO 2: Allocate memory for latte
    // using malloc() and sizeof(Drink).

    // TODO 3: Check whether malloc() returned NULL.
    // If allocation failed, print an error and return 1.

    // TODO 4: Initialize latte:
    // Name: "Latte"
    // Price: $4.50
    // Iced: No
    //
    // Use strcpy() and the -> operator.

    // TODO 5: Print the latte using print_drink().

    // =====================================
    // PART 2: USING A FUNCTION
    // =====================================

    printf("\n=====================================\n");
    printf("   PART 2: USING A FUNCTION\n");
    printf("=====================================\n");

    // TODO 7: Call create_drink() to create
    // an iced mocha costing $5.00.
    //
    // Store the returned pointer in mocha.

    // TODO 8: Check whether mocha is NULL.
    // If allocation failed, free latte
    // before returning 1.

    // TODO 9: Print mocha using print_drink().

    // =====================================
    // PART 3: MODIFYING DRINKS
    // =====================================

    printf("\n=====================================\n");
    printf("   PART 3: MODIFYING DRINKS\n");
    printf("=====================================\n");

    // TODO 10: Use increase_price() to
    // increase mocha's price by $1.00.

    // TODO 11: Use make_hot() to
    // change mocha from iced to hot.

    // TODO 12: Print mocha to verify
    // both changes.

    // =====================================
    // PART 4: FREEING MEMORY
    // =====================================

    printf("\n=====================================\n");
    printf("   PART 4: FREEING MEMORY\n");
    printf("=====================================\n");

    // TODO 13: Free the memory allocated
    // for latte and mocha.

    // TODO 14: Set both pointers to NULL
    // after freeing their memory.

    printf("\nMemory cleanup complete.\n");

    return 0;
}
