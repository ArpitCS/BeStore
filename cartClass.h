#ifndef CARTCLASS_H
#define CARTCLASS_H

#include "productClass.h"
#include "paymentClass.h"

class Cart
{
private:
    Product *cartItems[100];
    int quantities[100];
    int itemCount;

public:
    Cart() : itemCount(0) {}

    int getQuantity(int index) const
    {
        if (index >= 0 && index < itemCount)
        {
            return cartItems[index]->getQuantity();
        }
        else
        {
            return 0;
        }
    }

    void displayCart() const
    {
        if (itemCount == 0)
        {
            std::cout << "Your cart is empty." << std::endl;
            return;
        }

        for (int i = 0; i < itemCount; ++i)
        {
            int qt = quantities[i];
            cartItems[i]->printCart(i, qt);
        }
    }

    void addProduct(Product *product, int quantity)
    {
        if (itemCount < 100)
        {
            quantities[itemCount] = quantity;
            cartItems[itemCount++] = product;

            std::cout << "Added " << quantity << " of product " << product->getName() << " to cart." << std::endl;
        }
        else
        {
            std::cout << "Cart is full!" << std::endl;
        }
    }

    bool isEmpty() const
    {
        return itemCount == 0;
    }

    void checkout(Payment *payment)
    {
        std::cout << "Proceeding to checkout with payment: " << payment << std::endl;
    }

    void clearCart()
    {
        itemCount = 0;
        std::cout << "Cart cleared." << std::endl;
    }
};

#endif