// =========================================================
// Project: Inventory Management System
// Concepts: OOP, Inheritance, Polymorphism, File I/O,
//           Function Overloading, Vectors, Try-Catch
// =========================================================

#include "Inventory.h"
#include <iostream>
 
using namespace std;

int main() {
    InventoryManager myInventory;
    myInventory.loadProducts();

    int choice;
    do {
        cout << "\n=== Inventory Management System ===" << endl;
        cout << "1. Add a Product" << endl;
        cout << "2. View All Products" << endl;
        cout << "3. Search by ID" << endl;
        cout << "4. Search by Name" << endl;
        cout << "5. Restock a Product" << endl;
        cout << "6. Sell a Product (Calculate Total)" << endl;
        cout << "7. Calculate Total Inventory Value" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter choice: ";

        // Validation to prevent infinite loop if user enters a letter
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            int id, quantity;
            double price;
            string name, category;

            cout << "Enter ID: "; cin >> id;
            cin.ignore();
            cout << "Enter Name: ";     getline(cin, name);
            cout << "Enter Category: "; getline(cin, category);
            cout << "Enter Quantity: "; cin >> quantity;
            cout << "Enter Price (Rs.): "; cin >> price;

            myInventory.addProduct(id, name, category, quantity, price);
        }
        else if (choice == 2) {
            myInventory.displayAll();
        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: "; cin >> id;
            myInventory.searchProduct(id);    // Overloaded: int version
        }
        else if (choice == 4) {
            string name;
            cin.ignore();
            cout << "Enter Name to search: "; getline(cin, name);
            myInventory.searchProduct(name);  // Overloaded: string version
        }
        else if (choice == 5) {
            int id, qty;
            cout << "Enter Product ID to restock: "; cin >> id;
            cout << "Enter quantity to add: ";        cin >> qty;
            myInventory.restockProduct(id, qty);
        }
        else if (choice == 6) {
            int id, qty;
            cout << "Enter Product ID to sell: ";   cin >> id;
            cout << "Enter quantity to sell: ";     cin >> qty;
            myInventory.sellProduct(id, qty);
        }
        else if (choice == 7) {
            myInventory.calculateInventoryValue();
        }
        else if (choice != 8) {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 8);

    cout << "Exiting system. Goodbye!" << endl;
    return 0;
}
