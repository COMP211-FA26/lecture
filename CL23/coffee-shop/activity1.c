
#include <stdio.h>

typedef struct {
    char name[50];
    double price;
    int is_iced;  // 0 = hot, 1 = iced
} Drink;

int main(void) {
    Drink latte = {"Latte", 4.50, 0};

    printf("Drink: %s\n", latte.name);
    printf("Price: $%.2f\n", latte.price);

    // TODO 1: Print whether the latte is hot or iced.

    // TODO 2: Create an iced mocha that costs $5.00.

    // TODO 3: Increase the latte's price by $0.50.

    // TODO 4: Change the latte from hot to iced.

    // TODO 5: Print updated information for both drinks.

    return 0;
}