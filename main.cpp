#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
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
        cout << "Order No.\tDate and Time\tOrder Total\tOrder Items\n";
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
        cout << "1. Browse Products\n2. View Cart\n3. Checkout\n4. Clear Cart\n5. View Order History\n6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice < 1 || choice > 6) {
            cout << "Invalid choice. Please choose a number between 1 and 6.\n";
            continue;
        }

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

                if (cin.fail()) {
                    cout << "Invalid input. Please enter a number.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }

                if (prodChoice < 0 || prodChoice > PRODUCT_COUNT) {
                    cout << "Invalid product number. Please choose a number between 1 and " << PRODUCT_COUNT << ".\n";
                    break;
                }

                if (prodChoice == 0) {
                    break;
                }

                cout << "Enter quantity: ";
                cin >> quantity;

                if (cin.fail()) {
                    cout << "Invalid input. Please enter a number.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }

                if (quantity <= 0) {
                    cout << "Invalid quantity. Please enter a number greater than 0.\n";
                    break;
                }

                cart.addProduct(products[prodChoice - 1], quantity);
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
                cout << "\nChoose payment method (Credit Card/PayPal): ";
                cin >> paymentMethod;

                if (paymentMethod != "CreditCard" && paymentMethod != "PayPal") {
                    cout << "Invalid payment method. Please choose Credit Card or PayPal.\n";
                    break;
                }

                Payment* payment = nullptr;
                if (paymentMethod == "CreditCard") {
                    payment = new CreditCardPayment();
                } else if (paymentMethod == "PayPal") {
                    payment = new PayPalPayment();
                }

                if (payment) {
                    cart.checkout(payment);
                    // Save order to order_history.csv
                    ofstream file("order_history.csv", ios::app);
                    if (file.is_open()) {
                        srand(time(0));
                        int orderNo = rand() % 10000 + 1;
                        time_t now = time(0);
                        tm* ltm = localtime(&now);
                        string date = to_string(1900 + ltm->tm_year) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday);
                        string time = to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
                        double orderTotal = 0;
                        string orderItems;
                        for (int i = 0; i < PRODUCT_COUNT; i++) {
                            if (cart.getQuantity(i) > 0) {
                                orderTotal += products[i]->getPrice() * cart.getQuantity(i);
                                orderItems += products[i]->getName() + " x " + to_string(cart.getQuantity(i)) + ", ";
                            }
                        }
                        orderItems.pop_back();
                        orderItems.pop_back();
                        file << orderNo << "\t" << date << " " << time << "\t" << orderTotal << "\t" << orderItems << "\n";
                        file.close();
                    }
                    delete payment;
                } else {
                    cout << "Invalid payment method selected.\n";
                }
                break;
            }

            case 4:
                // Clear cart
                cart.clearCart();
                break;

            case 5:
                // View order history
                viewOrderHistory();
                break;

            case 6:
                cout << "Thank you for shopping!\n";
                break;
        }
    } while (choice != 6);

    // Cleanup dynamically allocated memory
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        delete products[i];
    }

    return 0;
}