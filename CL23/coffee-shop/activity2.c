
#include <stdio.h>

typedef struct {
    char name[50];
    double price;
    int is_iced;
} Drink;

void print_drink(Drink drink) {
    printf("%s: $%.2f (%s)\n", drink.name, drink.price,
           drink.is_iced ? "Iced" : "Hot");
}

void increase_price(Drink* drink, double amount) {
    // TODO 1: Increase the drink's price.
}

void make_iced(Drink* drink) {
    // TODO 2: Set is_iced to 1.
}

int main(void) {
    Drink latte = {"Latte", 4.50, 0};

    printf("Before changes:\n");
    print_drink(latte);

    // TODO 3: Increase the price by $0.50.

    // TODO 4: Make the latte iced.

    printf("\nAfter changes:\n");
    print_drink(latte);

    return 0;
}
