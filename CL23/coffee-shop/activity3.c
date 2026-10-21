
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct {
    char name[50];
    double price;
    int is_iced;
} Drink;

typedef struct {
    Drink drink;
    int quantity;
} LineItem;

typedef struct {
    char customer[50];
    LineItem items[MAX_ITEMS];
    int num_items;
} Order;

int main(void) {
    Drink latte = {"Latte", 4.50, 0};
    Drink mocha = {"Mocha", 5.00, 1};

    Order order = {0};
    strcpy(order.customer, "Alex");

    // Add 2 lattes
    order.items[0].drink = latte;
    order.items[0].quantity = 2;
    order.num_items = 1;

    // TODO 1: Add 1 iced mocha to the order.

    // TODO 2: Print the customer's name.

    // TODO 3: Loop through the items and print
    // each drink's name, quantity, and subtotal.

    // TODO 4: Calculate and print the total.

    // TODO 5: Increase the latte quantity to 3.

    // TODO 6: Calculate and print the updated total.

    return 0;
}
