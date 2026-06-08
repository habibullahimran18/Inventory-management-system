#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
// Abstract Base Class
class InventoryItem {
protected:
    int id;
    string name;
public:
    InventoryItem(int id, string name);
    virtual void displayInfo() = 0;   // Pure virtual function
    virtual ~InventoryItem() {}

    int getId();
    string getName();
};
// Derived Class
class Product : public InventoryItem {
private:
    string category;
    int quantity;
    double price;
public:
    Product(int id, string name, string category, int quantity, double price);

    void displayInfo() override;   // Polymorphism

    void setQuantity(int qty);
    void setPrice(double p);
    string getCategory();
    int getQuantity();
    double getPrice();
};
// Manager Class
class InventoryManager {
private:
    vector<Product> products;
    const string filename = "inventory_data.txt";

public:
    void loadProducts();
    void saveProducts();

    void addProduct(int id, string name, string category, int quantity, double price);
    void displayAll();

    // Function Overloading (same concept as searchBook)
    void searchProduct(int id);
    void searchProduct(string name);

    void restockProduct(int id, int quantity);
    void sellProduct(int id, int quantity);
    void calculateInventoryValue();
};

#endif
