#include <iostream>
#include <string>
#include <fstream>
#include "productClass.h"
#include "cartClass.h"
#include "orderClass.h"
#include "paymentClass.h"

using namespace std;

const int PRODUCT_COUNT = 18;

// Function to view order history from the order_history.csv file
void viewOrderHistory() {
    ifstream file("order_history.csv");
    if (file.is_open()) {
        string line;
        cout << "\n--- Order History ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "No order history found.\n";
    }
}

int main() {
    // Create products using normal arrays
    Product* products[PRODUCT_COUNT] = {
        new Book("The Great Gatsby", 12.99, 10, "1925", "F. Scott Fitzgerald", "Fiction"),
        new Book("To Kill a Mockingbird", 9.99, 10, "1960", "Harper Lee", "Fiction"),
        new Book("1984", 10.99, 10, "1949", "George Orwell", "Dystopian"),

        new Movie("The Godfather", 15.99, 15, "1972", "Francis Ford Coppola", "R"),
        new Movie("The Shawshank Redemption", 14.99, 15, "1994", "Frank Darabont", "R"),
        new Movie("The Dark Knight", 17.99, 15, "2008", "Christopher Nolan", "PG-13"),

        new Software("Windows 10", 119.99, 10, "2015", "PC", "10"),
        new Software("Microsoft Office", 149.99, 10, "2019", "PC", "2019"),
        new Software("Adobe Photoshop", 199.99, 10, "2020", "PC", "2020"),

        new Electronics("Apple iPhone 12", 799.99, 10, "iPhone 12", "Apple", "iPhone 12"),
        new Electronics("Samsung Galaxy S21", 899.99, 10, "Galaxy S21", "Samsung", "Galaxy S21"),
        new Electronics("Sony PlayStation 5", 499.99, 10, "PlayStation 5", "Sony", "PlayStation 5"),

        new Music("Abbey Road", 9.99, 10, "Abbey Road", "The Beatles", "Abbey Road"),
        new Music("Thriller", 8.99, 10, "Thriller", "Michael Jackson", "Thriller"),
        new Music("Back in Black", 7.99, 10, "Back in Black", "AC/DC", "Back in Black"),

        new Clothing("Shirt", 19.99, 10, "Black", "S", "Black"),
        new Clothing("Jeans", 29.99, 10, "Blue", "M", "Denim"),
        new Clothing("Sweater", 39.99, 10, "Red", "L", "Wool")
    };

    Cart cart;
    int choice;

    do {
        // Main menu
        cout << "\n--- Welcome to the Online Store ---\n";
        cout << "1. Browse Products\n2. View Cart\n3. Checkout\n4. View Order History\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Display products and allow user to add to cart
                cout << "\nAvailable Products:\n";
                for (int i = 0; i < PRODUCT_COUNT; i++) {
                    products[i]->print(i + 1);  // Pass product number
                }

                int prodChoice, quantity;
                cout << "Enter the product number to add to cart or 0 to go back: ";
                cin >> prodChoice;

                if (prodChoice > 0 && prodChoice <= PRODUCT_COUNT) {
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    cart.addProduct(products[prodChoice - 1], quantity);
                }
                break;
            }

            case 2:
                // Display cart
                cart.displayCart();
                break;

            case 3: {
                // Checkout and choose payment method
                if (cart.isEmpty()) {
                    cout << "Your cart is empty!\n";
                    break;
                }

                string paymentMethod;
                cout << "\nChoose payment method (CreditCard/PayPal): ";
                cin >> paymentMethod;

                Payment* payment = nullptr;
                if (paymentMethod == "CreditCard") {
                    payment = new CreditCardPayment();
                } else if (paymentMethod == "PayPal") {
                    payment = new PayPalPayment();
                }

                if (payment) {
                    cart.checkout(payment);
                    delete payment;
                } else {
                    cout << "Invalid payment method selected.\n";
                }
                break;
            }

            case 4:
                // View order history
                viewOrderHistory();
                break;

            case 5:
                cout << "Thank you for shopping!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    // Cleanup dynamically allocated memory
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        delete products[i];
    }

    return 0;
}
