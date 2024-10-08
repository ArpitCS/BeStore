#include <iostream>
#include "productClass.h" // Include the Product class header
#include "paymentClass.h" // Include the Payment class header

class Cart {
private:
    Product* cartItems[10]; // Fixed size array for cart items
    int itemCount; // To keep track of how many items are in the cart

public:
    Cart() : itemCount(0) {} // Initialize itemCount to 0

    void displayCart() const {
        if (itemCount == 0) { // Check if the cart is empty
            std::cout << "Your cart is empty." << std::endl;
            return;
        }

        for (int i = 0; i < itemCount; ++i) { // Use itemCount instead of cartItems.size()
            cartItems[i]->print(i); // Pass the index to print()
        }
    }

    void addProduct(Product* product, int quantity) {
        if (itemCount < 10) {
            cartItems[itemCount++] = product; // Add product and increment count
            std::cout << "Added " << quantity << " of product " << product->getName() << " to cart." << std::endl;
        } else {
            std::cout << "Cart is full!" << std::endl;
        }
    }

    bool isEmpty() const {
        return itemCount == 0; // Check if the cart is empty
    }

    void checkout(Payment* payment) {
        // Implement checkout logic (e.g., payment processing)
        std::cout << "Proceeding to checkout with payment: " << payment << std::endl;
    }

    // Additional functions can be added as needed (e.g., removeItem, clearCart)
};