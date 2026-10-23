
#include <stdio.h>

typedef struct {
    char name[50];
    double price;
    int is_iced;  // 0 = hot, 1 = iced
} Drink;

int main(void) {
    // Create our first drink.
    Drink latte = {"Latte", 4.50, 0};

    // Print the latte's information.
    printf("Drink: %s\n", latte.name);
    printf("Price: $%.2f\n", latte.price);

    // =====================================
    // CODE-ALONG
    // =====================================

    // TODO 1: Print whether the latte is
    // hot or iced.

    // TODO 2: Create a second Drink called mocha
    // It should be iced and cost $5.00.

    // TODO 3: Increase the latte's price by $0.50.

    // TODO 4: Change the latte from hot to iced.

    // TODO 5: Print the updated information
    // for both drinks (name, price, hot/iced).

    return 0;
}
