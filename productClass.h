class Product {
    private:
        string name;
        double price;
        int quantity;
        string description;
    public:
        Product(string n, double p, int q, string d) {
            name = n;
            price = p;
            quantity = q;
            description = d;
        }

        void setName(string n) {
            name = n;
        }

        void setPrice(double p) {
            price = p;
        }

        void setQuantity(int q) {
            quantity = q;
        }

        void setDescription(string d) {
            description = d;
        }

        string getName() {
            return name;
        }

        double getPrice() {
            return price;
        }

        int getQuantity() {
            return quantity;
        }

        string getDescription() {
            return description;
        }

        void print() {
            cout << "\tName: " << name << endl;
            cout << "\tPrice: " << price << endl;
            cout << "\tQuantity: " << quantity << endl;
            cout << "\tDescription: " << description << endl;
        }

        void addQuantity(int q) {
            quantity += q;
        }

        void removeQuantity(int q) {
            quantity -= q;
        }

        void display() {
            cout << "*-------------------------------------------------*" << endl;    
            cout << "\tName: " << name << endl;
            cout << "\tPrice: " << price << endl;
            cout << "\tQuantity: " << quantity << endl;
            cout << "*-------------------------------------------------*" << endl;    
        }
};

class Book : public Product {
    private:
        string author;
        string genre;
    public:
        Book(string n, double p, int q, string d, string a, string g) : Product(n, p, q, d) {
            author = a;
            genre = g;
        }

        void setAuthor(string a) {
            author = a;
        }

        void setGenre(string g) {
            genre = g;
        }

        string getAuthor() {
            return author;
        }

        string getGenre() {
            return genre;
        }

        void print() {
            cout << "*-------------------------------------------------*" << endl;    
            Product::print();
            cout << "\tAuthor: " << author << endl;
            cout << "\tGenre: " << genre << endl;
            cout << "*-------------------------------------------------*" << endl;    
        }
};

class Movie : public Product {
    private:
        string director;
        string rating;
    public:
        Movie(string n, double p, int q, string d, string di, string r) : Product(n, p, q, d) {
            director = di;
            rating = r;
        }

        void setDirector(string di) {
            director = di;
        }

        void setRating(string r) {
            rating = r;
        }

        string getDirector() {
            return director;
        }

        string getRating() {
            return rating;
        }

        void print() {
            cout << "*-------------------------------------------------*" << endl;    
            Product::print();
            cout << "\tDirector: " << director << endl;
            cout << "\tRating: " << rating << endl;
            cout << "*-------------------------------------------------*" << endl;
        }
};

class Software : public Product {
    private:
        string platform;
        string version;
    public:
        Software(string n, double p, int q, string d, string pl, string v) : Product(n, p, q, d) {
            platform = pl;
            version = v;
        }

        void setPlatform(string pl) {
            platform = pl;
        }

        void setVersion(string v) {
            version = v;
        }

        string getPlatform() {
            return platform;
        }

        string getVersion() {
            return version;
        }

        void print() {
            cout << "*-------------------------------------------------*" << endl;    
            Product::print();
            cout << "\tPlatform: " << platform << endl;
            cout << "\tVersion: " << version << endl;
            cout << "*-------------------------------------------------*" << endl;    
        }
};

class Electronics : public Product {
    private:
        string brand;
        string model;
    public:
        Electronics(string n, double p, int q, string d, string b, string m) : Product(n, p, q, d) {
            brand = b;
            model = m;
        }

        void setBrand(string b) {
            brand = b;
        }

        void setModel(string m) {
            model = m;
        }

        string getBrand() {
            return brand;
        }

        string getModel() {
            return model;
        }

        void print() {
            cout << "*-------------------------------------------------*" << endl;    
            Product::print();
            cout << "\tBrand: " << brand << endl;
            cout << "\tModel: " << model << endl;
            cout << "*-------------------------------------------------*" << endl;    
        }
};

class Music : public Product {
    private:
        string artist;
        string album;
    public:
        Music(string n, double p, int q, string d, string ar, string al) : Product(n, p, q, d) {
            artist = ar;
            album = al;
        }

        void setArtist(string ar) {
            artist = ar;
        }

        void setAlbum(string al) {
            album = al;
        }

        string getArtist() {
            return artist;
        }

        string getAlbum() {
            return album;
        }

        void print() {
            cout << "*-------------------------------------------------*" << endl;    
            Product::print();
            cout << "\tArtist: " << artist << endl;
            cout << "\tAlbum: " << album << endl;
            cout << "*-------------------------------------------------*" << endl;    
        }
};

class Clothing : public Product {
    private:
        string size;
        string color;
    public:
        Clothing(string n, double p, int q, string d, string s, string c) : Product(n, p, q, d) {
            size = s;
            color = c;
        }

        void setSize(string s) {
            size = s;
        }

        void setColor(string c) {
            color = c;
        }

        string getSize() {
            return size;
        }

        string getColor() {
            return color;
        }

        void print() {
            cout << "*-------------------------------------------------*" << endl;
            Product::print();
            cout << "\tSize: " << size << endl;
            cout << "\tColor: " << color << endl;
            cout << "*-------------------------------------------------*" << endl;    
        }
};