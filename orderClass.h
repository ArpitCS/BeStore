#ifndef ORDERCLASS_H
#define ORDERCLASS_H

#include "productClass.h"

class Order
{
private:
    Product *orderItems[10];
    int itemCount;
    int quantities[10];

public:
    Order() : itemCount(0) {}
    void displayOrder() const
    {
        if (itemCount == 0)
        {
            std::cout << "Your order is empty." << std::endl;
            return;
        }

        for (int i = 0; i < itemCount; ++i)
        {
            orderItems[i]->print(i);
            std::cout << "Quantity: " << quantities[i] << std::endl;
        }
    }

    void addItem(Product *product, int quantity)
    {
        if (itemCount < 10)
        {
            orderItems[itemCount] = product;
            quantities[itemCount] = quantity;
            itemCount++;
        }
        else
        {
            std::cout << "Order is full!" << std::endl;
        }
    }
};

#endif