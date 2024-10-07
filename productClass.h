#ifndef PRODUCTCLASS_H
#define PRODUCTCLASS_H

#include <iostream>
#include <string>

using namespace std;

// Helper function to print horizontal divider
void printDivider(int width) {
    cout << "+" << string(width, '-') << "+" << endl;
}

// Helper function to print a formatted line
void printFormattedLine(const string& label, const string& value, int width) {
    // Combine label and value, adjusting space for width
    string line = label + ": " + value;
    line += string(width - line.length() - 2, ' '); // Adjust spacing
    cout << line << endl;
}

// Base Product Class
class Product {
protected:
    string name;
    double price;
    int quantity;

public:
    Product(string n, double p, int q) : name(n), price(p), quantity(q) {}

    virtual void print() const = 0;

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
};

// Book Class
class Book : public Product {
    string publicationYear;
    string author;
    string genre;

public:
    Book(string n, double p, int q, string pubYear, string auth, string gen)
        : Product(n, p, q), publicationYear(pubYear), author(auth), genre(gen) {}

    void print() const override {
        int width = 50;  // Set width for card-like appearance
        printDivider(width);
        printFormattedLine("Book", name, width);
        printFormattedLine("Author", author, width);
        printFormattedLine("Publication Year", publicationYear, width);
        printFormattedLine("Genre", genre, width);
        printFormattedLine("Price", "$" + to_string(price), width);
        printFormattedLine("Quantity", to_string(quantity), width);
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

    void print() const override {
        int width = 50;
        printDivider(width);
        printFormattedLine("Movie", name, width);
        printFormattedLine("Director", director, width);
        printFormattedLine("Release Year", releaseYear, width);
        printFormattedLine("Rating", rating, width);
        printFormattedLine("Price", "$" + to_string(price), width);
        printFormattedLine("Quantity", to_string(quantity), width);
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

    void print() const override {
        int width = 50;
        printDivider(width);
        printFormattedLine("Software", name, width);
        printFormattedLine("Version", version, width);
        printFormattedLine("Platform", platform, width);
        printFormattedLine("Release Year", releaseYear, width);
        printFormattedLine("Price", "$" + to_string(price), width);
        printFormattedLine("Quantity", to_string(quantity), width);
        printDivider(width);
    }
};

// Electronics Class
class Electronics : public Product {
    string model;
    string brand;
    string series;

public:
    Electronics(string n, double p, int q, string mod, string br, string ser)
        : Product(n, p, q), model(mod), brand(br), series(ser) {}

    void print() const override {
        int width = 50;
        printDivider(width);
        printFormattedLine("Electronics", name, width);
        printFormattedLine("Model", model, width);
        printFormattedLine("Brand", brand, width);
        printFormattedLine("Series", series, width);
        printFormattedLine("Price", "$" + to_string(price), width);
        printFormattedLine("Quantity", to_string(quantity), width);
        printDivider(width);
    }
};

// Music Class
class Music : public Product {
    string album;
    string artist;
    string label;

public:
    Music(string n, double p, int q, string alb, string art, string lab)
        : Product(n, p, q), album(alb), artist(art), label(lab) {}

    void print() const override {
        int width = 50;
        printDivider(width);
        printFormattedLine("Music Album", album, width);
        printFormattedLine("Artist", artist, width);
        printFormattedLine("Label", label, width);
        printFormattedLine("Price", "$" + to_string(price), width);
        printFormattedLine("Quantity", to_string(quantity), width);
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

    void print() const override {
        int width = 50;
        printDivider(width);
        printFormattedLine("Clothing", name, width);
        printFormattedLine("Color", color, width);
        printFormattedLine("Size", size, width);
        printFormattedLine("Material", material, width);
        printFormattedLine("Price", "$" + to_string(price), width);
        printFormattedLine("Quantity", to_string(quantity), width);
        printDivider(width);
    }
};

#endif
