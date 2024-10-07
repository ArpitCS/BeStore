#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#include "productClass.h" 
#include "cartClass.h" 
#include "orderClass.h" 
/*
Product Types:
    1. Book -> Author, Genre
    2. Movie -> Director, Rating
    3. Software -> Platform, Version
    4. Electronics -> Brand, Model
    5. Music -> Artist, Album
    6. Clothing -> Size, Color
*/

void printCategory(Book *b, int totalBooks) {
    cout << "Books:" << endl;
    for (int i = 0; i < totalBooks; i++) {
        b[i].print();
    }
}

void printCategory(Movie *m, int totalMovies) {
    cout << "Movies:" << endl;
    for (int i = 0; i < totalMovies; i++) {
        m[i].print();
    }
}

void printCategory(Software *s, int totalSoftwares) {
    cout << "Softwares:" << endl;
    for (int i = 0; i < totalSoftwares; i++) {
        s[i].print();
    }
}

void printCategory(Electronics *e, int totalElectronics) {
    cout << "Electronics:" << endl;
    for (int i = 0; i < totalElectronics; i++) {
        e[i].print();
    }
}

void printCategory(Music *m, int totalMusic) {
    cout << "Music:" << endl;
    for (int i = 0; i < totalMusic; i++) {
        m[i].print();
    }
}

void printCategory(Clothing *c, int totalClothing) {
    cout << "Clothing:" << endl;
    for (int i = 0; i < totalClothing; i++) {
        c[i].print();
    }
}

int main() {
    
    // Products
    Book books[] = {
        Book("The Great Gatsby", 12.99, 10, "1925", "F. Scott Fitzgerald", "Fiction"),
        Book("To Kill a Mockingbird", 9.99, 15, "1960", "Harper Lee", "Fiction"),
        Book("1984", 10.99, 20, "1949", "George Orwell", "Dystopian"),
        Book("The Catcher in the Rye", 11.99, 25, "1951", "J.D. Salinger", "Fiction"),
        Book("The Hobbit", 13.99, 30, "1937", "J.R.R. Tolkien", "Fantasy")
    };
    int totalBooks = sizeof(books) / sizeof(books[0]);

    Movie movies[] = {
        Movie("The Shawshank Redemption", 14.99, 10, "1994", "Frank Darabont", "R"),
        Movie("The Godfather", 15.99, 15, "1972", "Francis Ford Coppola", "R"),
        Movie("The Dark Knight", 16.99, 20, "2008", "Christopher Nolan", "PG-13"),
        Movie("Pulp Fiction", 17.99, 25, "1994", "Quentin Tarantino", "R"),
        Movie("The Lord of the Rings: The Return of the King", 18.99, 30, "2003", "Peter Jackson", "PG-13")
    };
    int totalMovies = sizeof(movies) / sizeof(movies[0]);

    Software softwares[] = {
        Software("Windows 10", 119.99, 10, "2015", "PC", "10"),
        Software("macOS Big Sur", 129.99, 15, "2020", "Mac", "11"),
        Software("Ubuntu 20.04", 139.99, 20, "2020", "Linux", "20.04"),
        Software("iOS 14", 149.99, 25, "2020", "iPhone", "14"),
        Software("Android 11", 159.99, 30, "2020", "Android", "11")
    };
    int totalSoftwares = sizeof(softwares) / sizeof(softwares[0]);

    Electronics electronics[] = {
        Electronics("Apple iPhone 12", 799.99, 10, "iPhone 12", "Apple", "iPhone 12"),
        Electronics("Samsung Galaxy S21", 899.99, 15, "Galaxy S21", "Samsung", "Galaxy S21"),
        Electronics("Dell XPS 13", 999.99, 20, "XPS 13", "Dell", "XPS 13"),
        Electronics("HP Spectre x360", 1099.99, 25, "Spectre x360", "HP", "Spectre x360"),
        Electronics("Lenovo ThinkPad x1 Carbon", 1199.99, 30, "ThinkPad X1 Carbon", "Lenovo", "ThinkPad X1 Carbon")
    };
    int totalElectronics = sizeof(electronics) / sizeof(electronics[0]);

    Music music[] = {
        Music("Abbey Road", 9.99, 10, "Abbey Road", "The Beatles", "Abbey Road"),
        Music("Thriller", 10.99, 15, "Thriller", "Michael Jackson", "Thriller"),
        Music("Goodbye Yellow Brick Road", 11.99, 20, "Goodbye Yellow Brick Road", "Elton John", "Goodbye Yellow Brick Road"),
        Music("A Night at the Opera", 12.99, 25, "A Night at the Opera", "Queen", "A Night at the Opera"),
        Music("Led Zeppelin IV", 13.99, 30, "Led Zeppelin IV", "Led Zeppelin", "Led Zeppelin IV")
    };
    int totalMusic = sizeof(music) / sizeof(music[0]);

    Clothing clothing[] = {
        Clothing("Shirt", 19.99, 10, "Black", "S", "Black"),
        Clothing("T-Shirt", 20.99, 15, "White", "M", "White"),
        Clothing("Trousers", 21.99, 20, "Blue", "L", "Blue"),
        Clothing("Oversized T-Shirt", 22.99, 25, "Red", "XL", "Red"),
        Clothing("Jacket", 23.99, 30, "Green", "XXL", "Green")
    };
    int totalClothing = sizeof(clothing) / sizeof(clothing[0]);

    // Print Products
    printCategory(books, totalBooks);
    printCategory(movies, totalMovies);
    printCategory(softwares, totalSoftwares);
    printCategory(electronics, totalElectronics);
    printCategory(music, totalMusic);
    printCategory(clothing, totalClothing);

    return 0;
}
