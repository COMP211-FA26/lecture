
#include <stdio.h>

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
// CODE-ALONG FUNCTIONS
// =====================================

// 1: Increase the drink's price
// by the given amount.
void increase_price(Drink* drink, double amount) {}

// 2: Change the drink to iced.
void make_iced(Drink* drink) {}

// =====================================
// GROUP ACTIVITY FUNCTIONS
// =====================================

// TODO 1: Change the drink to hot.
void make_hot(Drink* drink) {}

// TODO 4: Swap the prices of two drinks.
// Hint: Use a temporary variable.
void swap_prices(Drink* drink1, Drink* drink2) {}

int main(void) {
    // Create our first drink.
    Drink latte = {"Latte", 4.50, 0};

    printf("\n=====================================\n");
    printf("       ORIGINAL DRINK\n");
    printf("=====================================\n");
    print_drink(latte);

    // =====================================
    // CODE-ALONG
    // =====================================

    // 3: Call increase_price() to
    // increase the latte's price by $0.50.

    // 4: Call make_iced() to
    // change the latte from hot to iced.

    printf("\n=====================================\n");
    printf("       AFTER UPDATING LATTE\n");
    printf("=====================================\n");
    print_drink(latte);

    // =====================================
    // GROUP ACTIVITY
    // =====================================

    // Scroll up for TODO 1

    // TODO 2: Create an iced mocha
    // that costs $5.00.
    Drink mocha;

    // TODO 3: Use increase_price() to
    // increase the mocha's price by $1.00.
    // Then use make_hot() to make it hot.

    printf("\n=====================================\n");
    printf("       AFTER UPDATING MOCHA\n");
    printf("=====================================\n");
    print_drink(mocha);

    // Scroll up for TODO 4

    // TODO 5: Call swap_prices() to swap
    // the prices of latte and mocha.

    printf("\n=====================================\n");
    printf("       AFTER SWAPPING PRICES\n");
    printf("=====================================\n");

    // TODO 6: Print both drinks to
    // verify that their prices were swapped.

    return 0;
}
