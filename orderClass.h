#ifndef ORDERCLASS_H
#define ORDERCLASS_H

#include <iostream>
#include "productClass.h"

const int MAX_ORDER_ITEMS = 10;

class Order {
    int orderID;
    Product* orderItems[MAX_ORDER_ITEMS];
    int itemCount;

public:
    Order(int id) : orderID(id), itemCount(0) {}

    void addProductToOrder(Product* product) {
        if (itemCount < MAX_ORDER_ITEMS) {
            orderItems[itemCount] = product;
            itemCount++;
        } else {
            cout << "Order has too many items.\n";
        }
    }

    void displayOrder() {
        cout << "\nOrder ID: " << orderID << endl;
        for (int i = 0; i < itemCount; i++) {
            orderItems[i]->print();
        }
    }
};

#endif
