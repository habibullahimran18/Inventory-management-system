📦 Inventory Management System
OOP Final Project — C++
A console-based Inventory Management System built in C++ to demonstrate core Object-Oriented Programming (OOP) principles. The system allows users to seamlessly add products, view the complete inventory catalog, search for specific items, restock products, process sales with automatic total calculation, and generate inventory value reports. All data is persistently stored using file handling.

✨ Core Features

Inventory Management: Add new products and view the complete product catalog.
Smart Search: Search for products by either their unique ID or Name (Function Overloading).
Restock Module: Increase the quantity of any existing product with a single operation.
Sales Processing: Sell products with live stock validation and automatic total calculation.
Inventory Value Report: Compute and display the total monetary worth of all stock in the system.
Data Persistence: Automatically loads and saves all inventory data to a local text file (inventory_data.txt), ensuring no data is lost between sessions.


🧠 OOP Concepts Implemented

Encapsulation: Class variables (id, name, category, quantity, price) are private and strictly accessed via public getter and setter methods.
Abstraction: The InventoryItem class acts as an abstract blueprint, utilizing a pure virtual function (virtual void displayInfo() = 0;).
Inheritance: The Product class securely inherits core attributes and methods from the base InventoryItem class.
Static Polymorphism: The searchProduct() method is overloaded to accept either an int (ID) or a string (Name).
Dynamic Polymorphism: The displayInfo() method is overridden in the derived Product class to provide a specific, formatted implementation.
Exception Handling: A try-catch block in loadProducts() silently skips any corrupt or malformed lines in the data file, preventing crashes.


👥 Group Members & Work Breakdown
This project was developed collaboratively. Responsibilities and core module development were divided as follows:
1. All Group Members

Role: GitHub Repository Management & Main Program Integration.
Details: Handled version control, repository setup, and merging. Developed the central main.cpp execution flow, implementing the interactive user menu with input validation and ensuring all components compiled and integrated flawlessly.


2. M junaid zahid(2025-AI-365)

Role: Class Architecture & Base Abstraction.
Details: Designed the header file (Inventory.h) and implemented the Abstract Base Class (InventoryItem), setting up the pure virtual function displayInfo() and the protected attributes id and name. Established the overall class hierarchy for the project.


3. Habibullah Imran(2025-AI-344)

Role: Core Product Mechanics & Dynamic Polymorphism.
Details: Implemented the derived Book class Product. Handled constructors, full encapsulation (getters/setters for category, quantity, and price), and successfully overrode the displayInfo() method for accurate, formatted product data output including live stock status.


4. Syed Hassan Murtaza(2025-AI-327)

Role: Search Modules, Sales & Restock Logic.
Details: Developed the displayAll() function and engineered the overloaded searchProduct() methods, allowing the system to process both integer and string search queries. Also implemented restockProduct(), sellProduct() with full stock validation, and calculateInventoryValue() for the financial report.


5. M. Umer(2025-AI-340)

Role: Data Persistence & File Handling.
Details: Engineered the loadProducts() and saveProducts() functions in Inventory.cpp. Implemented robust stringstream parsing to safely read and write comma-separated values to the database file. Added empty-line filtering and a try-catch block to ensure the program handles corrupt data gracefully without crashing
