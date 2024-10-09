#ifndef PAYMENTCLASS_H
#define PAYMENTCLASS_H

class Payment {
public:
    virtual void processPayment(double amount) = 0; // Pure virtual function
};

class CreditCardPayment : public Payment {
public:
    void processPayment(double amount) override {
        cout << "Processing credit card payment of $" << amount << endl;
        if (amount > 1000) {
            throw "Error: Payment exceeds credit limit.";
        }
        cout << "Credit card payment successful.\n";
    }
};

class PayPalPayment : public Payment {
public:
    void processPayment(double amount) override {
        cout << "Processing PayPal payment of $" << amount << endl;
        if (amount > 5000) {
            throw "Error: PayPal account has insufficient funds.";
        }
        cout << "PayPal payment successful.\n";
    }
};

#endif