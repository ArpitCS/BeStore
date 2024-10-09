#ifndef ORDERCLASS_H
#define ORDERCLASS_H

#include "productClass.h" // Include the Product class header

class Order {
private:
    Product* orderItems[10]; // Fixed size array for order items
    int itemCount; // To keep track of how many items are in the order
    int quantities[10]; // Array to store quantities of each product

public:
    Order() : itemCount(0) {} // Initialize itemCount to 0

    void displayOrder() const {
        if (itemCount == 0) { // Check if the order is empty
            std::cout << "Your order is empty." << std::endl;
            return;
        }

        for (int i = 0; i < itemCount; ++i) { // Use itemCount instead of orderItems.size()
            orderItems[i]->print(i); // Pass the index to print()
            std::cout << "Quantity: " << quantities[i] << std::endl; // Output the quantity
        }
    }

    void addItem(Product* product, int quantity) {
        if (itemCount < 10) {
            orderItems[itemCount] = product; // Add product
            quantities[itemCount] = quantity; // Set quantity
            itemCount++; // Increment itemCount
        } else {
            std::cout << "Order is full!" << std::endl;
        }
    }

    // Additional functions can be added as needed (e.g., removeItem, clearOrder)
};

 #endif