# "BeStore": Online Store Application

## Project Goal
Create an online store application that allows users to browse products, add items to the cart, checkout, and manage orders.

## Features
- Browse products
- Add products to the cart
- Checkout process
- Order management

## Required Concepts

### Classes
- **Product**: Represents a product with attributes like name, price, quantity, and description.
- **Cart**: Represents a shopping cart with methods to add, remove, and view products.
- **Order**: Represents an order with attributes like order ID, customer information, and products.

### Data Structures
- Use arrays or files to store products in the catalog and cart.

### Inheritance
- Create derived classes for different product types (e.g., Book, Electronics) to add specific attributes or methods.

### Polymorphism
- Utilize polymorphism to handle different payment methods (e.g., CreditCardPayment, PayPalPayment) through a base `Payment` class.

### Exception Handling
- Implement exception handling to catch errors like invalid input, out-of-stock products, or payment processing failures.

## Rubrics

- **Functionality**: The application should allow users to browse products, add to cart, checkout, and view order history.
  
- **Data Structures**: Use arrays or files to store products and orders.

- **Object-Oriented Design**: Use classes and objects to model the application's entries.

- **Inheritance and Polymorphism**: Implement inheritance and polymorphism for product types and payment methods.

- **Error Handling**: Handle potential errors gracefully using exceptions.

- **User Interface**: Provide a user-friendly interface for interacting with the application.

- **Efficiency**: Optimize the application for performance, especially when dealing with large product catalogs and many orders.

## Usage
- Clone the repository to your local machine.
- Compile and run the application.
- Follow the on-screen instructions to browse products, add to the cart, and complete your order.

## Installation
1. Ensure you have a C++ compiler installed (e.g., g++, clang).
2. Clone the repository:
   ```bash
   git clone https://github.com/arpitcs/bestore.git
   ```
3. Navigate to the project directory:
   ```bash
   cd bestore
   ```
4. Compile the code:
   ```bash
   g++ -o bestore main.cpp
   ```
5. Run the application:
   ```bash
   ./bestore
   ```

## Contributing
Currently, This repository will not be accepting any Open-Source Contributions due to being a part of College Assessment.