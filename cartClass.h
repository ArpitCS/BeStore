#include <iostream>
#include "productClass.h" // Include the Product class header
#include "paymentClass.h" // Include the Payment class header

class Cart {
private:
    Product* cartItems[100]; // Fixed size array for cart items
    int quantities[100]; // Array to store quantities of each product
    int itemCount; // To keep track of how many items are in the cart

public:
    Cart() : itemCount(0) {} // Initialize itemCount to 0

    int getQuantity(int index) const {
        if (index >= 0 && index < itemCount) {
            return cartItems[index]->getQuantity();
        } else {
            return 0;
        }
    }

    void displayCart() const {
        if (itemCount == 0) { // Check if the cart is empty
            std::cout << "Your cart is empty." << std::endl;
            return;
        }

        for (int i = 0; i < itemCount; ++i) { // Use itemCount instead of cartItems.size()
            int qt = quantities[i];
            cartItems[i]->printCart(i, qt); // Pass the index to print()
        }
    }

    void addProduct(Product* product, int quantity) {
        if (itemCount < 100) {
            quantities[itemCount] = quantity; // Set quantity
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