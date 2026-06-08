#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/* ========================================
   PART 2: Class Architecture & Base Abstraction
   Role: M junaid zahid (2025-AI-365)
   Details: Abstract Base Class (InventoryItem),
   pure virtual function, and protected attributes
   ======================================== */

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

/* ========================================
   PART 3: Core Product Mechanics & Dynamic Polymorphism
   Role: Habibullah Imran (2025-AI-344)
   Details: Derived Product class with full encapsulation,
   constructors, and overridden displayInfo()
   ======================================== */

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

/* ========================================
   PART 4 & 5: Search/Sales Logic + Data Persistence
   PART 4: Syed Hassan Murtaza (2025-AI-327)
           - Search, Sales, Restock, Calculate Value
   PART 5: M. Umer (2025-AI-340)
           - File I/O: loadProducts(), saveProducts()
   ======================================== */

// Manager Class
class InventoryManager {
private:
    vector<Product> products;
    const string filename = "inventory_data.txt";

public:
    // ===== PART 5: Data Persistence (M. Umer) =====
    void loadProducts();
    void saveProducts();
    // ===== END PART 5 =====

    void addProduct(int id, string name, string category, int quantity, double price);
    
    // ===== PART 4: Search & Sales Logic (Syed Hassan Murtaza) =====
    void displayAll();
    void searchProduct(int id);        // Function Overloading - search by ID
    void searchProduct(string name);   // Function Overloading - search by Name
    void restockProduct(int id, int quantity);
    void sellProduct(int id, int quantity);
    void calculateInventoryValue();
    // ===== END PART 4 =====
};

#endif
