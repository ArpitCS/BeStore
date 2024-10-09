#ifndef PRODUCTCLASS_H
#define PRODUCTCLASS_H

#include <iostream>
#include <string>

using namespace std;

// Helper function to print horizontal divider
void printDivider(int width) {
    cout << "+" << string(width, '-') << "+" << endl;
}

// Base Product Class
class Product {
protected:
    string name;
    double price;
    int quantity;

public:
    Product(string n, double p, int q) : name(n), price(p), quantity(q) {}

    virtual void print(int productNumber) const = 0;

    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    void removeQuantity(int qty) {
        if (quantity >= qty) {
            quantity -= qty;
        } else {
            cout << "Insufficient stock." << endl;
        }
    }

    void printCart(int productNumber, int amt) const {
        string tempNumber = "[" + to_string(productNumber) + "]";
        int width = 50;
        printDivider(width);
        cout << "Product Number: " << tempNumber << endl;
        cout << "Product: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Amount: " << amt << endl;
        printDivider(width);
    }
};

// Book Class
class Book : public Product {
    string publicationYear;
    string author;
    string genre;

public:
    Book(string n, double p, int q, string pubYear, string auth, string gen)
        : Product(n, p, q), publicationYear(pubYear), author(auth), genre(gen) {}

    void print(int productNumber) const override {
        string tempNumber = "[" + to_string(productNumber) + "]";
        int width = 50;
        printDivider(width);
        cout << "Product Number: " << tempNumber << endl;
        cout << "Book: " << name << endl;
        cout << "Author: " << author << endl;
        cout << "Publication Year: " << publicationYear << endl;
        cout << "Genre: " << genre << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        printDivider(width);
    }
};

// Movie Class
class Movie : public Product {
    string releaseYear;
    string director;
    string rating;

public:
    Movie(string n, double p, int q, string rYear, string dir, string rat)
        : Product(n, p, q), releaseYear(rYear), director(dir), rating(rat) {}

    void print(int productNumber) const override {
        string tempNumber = "[" + to_string(productNumber) + "]";
        int width = 50;
        printDivider(width);
        cout << "Product Number: " << tempNumber << endl;
        cout << "Movie: " << name << endl;
        cout << "Director: " << director << endl;
        cout << "Release Year: " << releaseYear << endl;
        cout << "Rating: " << rating << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        printDivider(width);
    }
};

// Software Class
class Software : public Product {
    string releaseYear;
    string platform;
    string version;

public:
    Software(string n, double p, int q, string rYear, string plat, string ver)
        : Product(n, p, q), releaseYear(rYear), platform(plat), version(ver) {}

    void print(int productNumber) const override {
        string tempNumber = "[" + to_string(productNumber) + "]";
        int width = 50;
        printDivider(width);
        cout << "Product Number: " << tempNumber << endl;
        cout << "Software: " << name << endl;
        cout << "Version: " << version << endl;
        cout << "Platform: " << platform << endl;
        cout << "Release Year: " << releaseYear << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        printDivider(width);
    }
};

// Electronics Class
class Electronics : public Product {
    string model;
    string brand;
    string specs;

public:
    Electronics(string n, double p, int q, string mod, string br, string sp)
        : Product(n, p, q), model(mod), brand(br), specs(sp) {}

    void print(int productNumber) const override {
        string tempNumber = "[" + to_string(productNumber) + "]";
        int width = 50;
        printDivider(width);
        cout << " Product Number: " << tempNumber << endl;
        cout << "Electronics: " << name << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Specs: " << specs << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        printDivider(width);
    }
};

// Music Class
class Music : public Product {
    string albumName;
    string artist;
    string genre;

public:
    Music(string n, double p, int q, string alb, string art, string gen)
        : Product(n, p, q), albumName(alb), artist(art), genre(gen) {}

    void print(int productNumber) const override {
        string tempNumber = "[" + to_string(productNumber) + "]";
        int width = 50;
        printDivider(width);
        cout << "Product Number: " << tempNumber << endl;
        cout << "Music Album: " << name << endl;
        cout << "Artist: " << artist << endl;
        cout << "Album: " << albumName << endl;
        cout << "Genre: " << genre << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        printDivider(width);
    }
};

// Clothing Class
class Clothing : public Product {
    string color;
    string size;
    string material;

public:
    Clothing(string n, double p, int q, string col, string sz, string mat)
        : Product(n, p, q), color(col), size(sz), material(mat) {}

    void print(int productNumber) const override {
        string tempNumber = "[" + to_string(productNumber) + "]";
        int width = 50;
        printDivider(width);
        cout << "Product Number: " << tempNumber << endl;
        cout << "Clothing: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Size: " << size << endl;
        cout << "Material: " << material << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        printDivider(width);
    }
};

#endif