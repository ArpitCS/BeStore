#ifndef CARTCLASS_H
#define CARTCLASS_H

#include <iostream>
#include "productClass.h"
#include "paymentClass.h"

const int MAX_CART_ITEMS = 10;

class Cart {
    Product* cartItems[MAX_CART_ITEMS];
    int quantities[MAX_CART_ITEMS];
    int itemCount;

public:
    Cart() : itemCount(0) {}

    void addProduct(Product* product, int quantity) {
        if (product->getQuantity() >= quantity) {
            if (itemCount < MAX_CART_ITEMS) {
                cartItems[itemCount] = product;
                quantities[itemCount] = quantity;
                itemCount++;
                product->removeQuantity(quantity);
                cout << quantity << " " << product->getName() << "(s) added to cart.\n";
            } else {
                cout << "Cart is full!\n";
            }
        } else {
            cout << "Sorry, not enough stock available.\n";
        }
    }

    void displayCart() {
        if (itemCount == 0) {
            cout << "Your cart is empty!\n";
            return;
        }

        cout << "\n--- Your Cart ---\n";
        double total = 0;
        for (int i = 0; i < itemCount; i++) {
            cartItems[i]->print();
            cout << "Quantity: " << quantities[i] << endl;
            total += cartItems[i]->getPrice() * quantities[i];
        }
        cout << "\nTotal: $" << total << endl;
    }

    bool isEmpty() {
        return itemCount == 0;
    }

    void checkout(Payment* payment) {
        double total = 0;
        for (int i = 0; i < itemCount; i++) {
            total += cartItems[i]->getPrice() * quantities[i];
        }

        try {
            payment->processPayment(total);
            cout << "Checkout successful! Your order is complete.\n";
            itemCount = 0;  // Clear the cart after checkout
        } catch (const char* errMsg) {
            cout << errMsg << endl;
        }
    }
};

#endif
