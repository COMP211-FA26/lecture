
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    double price;
    int is_iced;  // 0 = hot, 1 = iced
} Drink;

// Print a drink's information.
void print_drink(Drink drink) {
    printf("%s: $%.2f (%s)\n", drink.name, drink.price,
           drink.is_iced ? "Iced" : "Hot");
}

// =====================================
// GROUP ACTIVITY FUNCTION
// =====================================

// TODO: Create a function to rename a drink.
// Use strcpy() to copy new_name into drink->name.
// Assume the new name fits in the array.
void rename_drink(Drink* drink, const char new_name[]) {}

// =====================================
// CODE-ALONG 2 FUNCTION
// =====================================

// Add "Iced " to the beginning of a drink's name.
//
// Example: "Green Tea" -> "Iced Green Tea"
void add_iced_prefix(Drink* drink) {
    // CODE-ALONG:
    // 1. Create a temporary character array.
    // 2. Use strcpy() to copy "Iced " into it.
    // 3. Use strcat() to append the original name.
    // 4. Copy the result back into drink->name.
    // 5. Set is_iced to 1.
    //
    // Assume the combined name fits in the array.
}

int main(void) {
    printf("\n=====================================\n");
    printf("   CODE-ALONG 1: WORKING WITH STRINGS\n");
    printf("=====================================\n");

    Drink latte = {"Latte", 4.50, 0};

    printf("\nBefore renaming:\n");
    print_drink(latte);

    // Try uncommenting this line:
    // latte.name = "Vanilla Latte";

    // Why doesn't it compile?
    // Arrays cannot be assigned using = in C.

    // Use strcpy() instead.
    // strcpy(latte.name, "Vanilla Latte");

    printf("\nAfter renaming:\n");
    print_drink(latte);

    printf("\n=====================================\n");
    printf("GROUP ACTIVITY 1: RENAME DRINK WITH STRCPY\n");
    printf("=====================================\n");

    // Group Activity: Rename another drink.
    //
    // TODO 1: Create a Drink called mocha:
    // Name: "Mocha"
    // Price: $5.00
    // Iced: Yes

    // TODO 2: Print the drink.

    // TODO 3: Use strcpy() to rename it to "White Chocolate Mocha".

    // TODO 4: Print the drink again.

    printf("\n=============================================\n");
    printf("GROUP ACTIVITY 2: RENAME DRINK WITH RENAME_DRINK\n");
    printf("=============================================\n");

    // TODO 1: Complete rename_drink() function above.

    // TODO 2: Call it to rename latte to "Caramel Latte".

    // TODO 3: Print latte to verify the change.

    // TODO 4: Create a Drink called tea:
    // Name: "Tea"
    // Price: $3.00
    // Iced: No

    // TODO 5: Use rename_drink() to change its name to "Green Tea".

    // TODO 6: Print tea to verify the change.

    printf("\n=====================================\n");
    printf("   CODE-ALONG 2: COMBINING STRINGS\n");
    printf("=====================================\n");

    // Complete add_iced_prefix() together.
    //
    // Call it to change tea's name from
    // "Green Tea" to "Iced Green Tea".
    //
    // Print tea to verify the change.

    return 0;
}
