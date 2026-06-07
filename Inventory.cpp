#include "Inventory.h"
InventoryItem::InventoryItem(int id, string name) {
    this->id = id;
    this->name = name;
}
int InventoryItem::getId() { return id; }
string InventoryItem::getName() { return name; }
Product::Product(int id, string name, string category, int quantity, double price)
    : InventoryItem(id, name) {
    this->category = category;
    this->quantity = quantity;
    this->price = price;
}

void Product::displayInfo() {
    cout << "ID: " << id
         << " | Name: " << name
         << " | Category: " << category
         << " | Qty: " << quantity
         << " | Price: Rs. " << price
         << " | Status: " << (quantity > 0 ? "In Stock" : "Out of Stock")
         << endl;
}

void Product::setQuantity(int qty) { quantity = qty; }
void Product::setPrice(double p) { price = p; }
string Product::getCategory() { return category; }
int Product::getQuantity() { return quantity; }
double Product::getPrice() { return price; }
void InventoryManager::loadProducts() {
    ifstream file(filename);
    if (!file) return;

    string line, name, category, qtyStr, priceStr;

    while (getline(file, line)) {
        if (line.empty() || line.find_first_not_of(" \t\r\n") == string::npos) {
            continue;
        }

        stringstream ss(line);
        string tempId;
        int id = 0, quantity = 0;
        double price = 0.0;

        try {
            getline(ss, tempId, ',');  id = stoi(tempId);
            getline(ss, name, ',');
            getline(ss, category, ',');
            getline(ss, qtyStr, ','); quantity = stoi(qtyStr);
            getline(ss, priceStr, ','); price = stod(priceStr);

            products.push_back(Product(id, name, category, quantity, price));
        } catch (...) {
            continue;
        }
    }
    file.close();
}

void InventoryManager::saveProducts() {
    ofstream file(filename);
    for (Product& p : products) {
        file << p.getId() << ","
             << p.getName() << ","
             << p.getCategory() << ","
             << p.getQuantity() << ","
             << p.getPrice() << "\n";
    }
    file.close();
}

void InventoryManager::addProduct(int id, string name, string category, int quantity, double price) {
    products.push_back(Product(id, name, category, quantity, price));
    saveProducts();
    cout << "Product added successfully!" << endl;
}

void InventoryManager::displayAll() {
    if (products.empty()) {
        cout << "Inventory is empty." << endl;
        return;
    }
    cout << "\n--- All Products ---" << endl;
    for (Product& p : products) {
        p.displayInfo();   
    }
}

void InventoryManager::searchProduct(int id) {
    for (Product& p : products) {
        if (p.getId() == id) {
            p.displayInfo();
            return;
        }
    }
    cout << "Product not found." << endl;
}

void InventoryManager::searchProduct(string name) {
    for (Product& p : products) {
        if (p.getName() == name) {
            p.displayInfo();
            return;
        }
    }
    cout << "Product not found." << endl;
}

void InventoryManager::restockProduct(int id, int quantity) {
    for (Product& p : products) {
        if (p.getId() == id) {
            p.setQuantity(p.getQuantity() + quantity);
            saveProducts();
            cout << "Success: '" << p.getName()
                 << "' restocked. New quantity: " << p.getQuantity() << endl;
            return;
        }
    }
    cout << "Error: Product ID not found." << endl;
}

void InventoryManager::sellProduct(int id, int quantity) {
    for (Product& p : products) {
        if (p.getId() == id) {
            if (p.getQuantity() == 0) {
                cout << "Error: '" << p.getName() << "' is out of stock." << endl;
            } else if (p.getQuantity() < quantity) {
                cout << "Error: Not enough stock. Available: " << p.getQuantity() << endl;
            } else {
                p.setQuantity(p.getQuantity() - quantity);
                saveProducts();
                double total = quantity * p.getPrice();
                cout << "\n--- Sale Processed ---" << endl;
                cout << "Product: " << p.getName() << endl;
                cout << "Qty Sold: " << quantity << endl;
                cout << "Total Amount: Rs. " << total << endl;
                cout << "Remaining Stock: " << p.getQuantity() << endl;
                cout << "----------------------\n" << endl;
            }
            return;
        }
    }
    cout << "Error: Product ID not found." << endl;
}

void InventoryManager::calculateInventoryValue() {
    if (products.empty()) {
        cout << "Inventory is empty." << endl;
        return;
    }
    double total = 0.0;
    cout << "\n--- Inventory Value Report ---" << endl;
    for (Product& p : products) {
        double val = p.getQuantity() * p.getPrice();
        cout << p.getName() << " -> Qty: " << p.getQuantity()
             << " x Rs. " << p.getPrice()
             << " = Rs. " << val << endl;
        total += val;
    }
    cout << "------------------------------" << endl;
    cout << "TOTAL INVENTORY VALUE: Rs. " << total << endl;
    cout << "------------------------------\n" << endl;
}
