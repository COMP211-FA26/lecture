#include <stdio.h>
#include <string.h>

#define NUM_ITEMS 3

typedef struct {
    char name[50];
    double price;
    int is_iced;
} Drink;

void print_drink(Drink* drink) {
    printf("%s: $%.2f (%s)\n", drink->name, drink->price,
           drink->is_iced ? "Iced" : "Hot");
}

// Increase a drink's price.
void increase_price(Drink* drink, double amount) { drink->price += amount; }

// CODE-ALONG 4: Increase the price of every drink
// by the given amount.
void increase_all_prices(Drink menu[], int count, double amount) {
    for (int i = 0; i < count; i++) {
        increase_price(&menu[i], amount);
    }
}

int main(void) {
    Drink menu[NUM_ITEMS] = {
        {"Latte", 4.50, 0}, {"Mocha", 5.00, 1}, {"Green Tea", 3.00, 0}};

    // CODE-ALONG 1:
    // Print the name of the first drink.
    printf("%s\n", menu[0].name);

    // CODE-ALONG 2:
    // Increase the price of the second
    // drink by $0.50.
    increase_price(&menu[1], 0.50);

    // CODE-ALONG 3:
    // Use a loop to print every drink.
    for (int i = 0; i < NUM_ITEMS; i++) {
        print_drink(&menu[i]);
    }

    // CODE-ALONG 4: Use increase_all_prices() to increase
    // the price of every drink by $1.
    increase_all_prices(menu, NUM_ITEMS, 1.00);

    return 0;
}