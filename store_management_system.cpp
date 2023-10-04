#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a Product structure to store product information
struct Product {
    int id;
    string name;
    double price;
    int quantity;
};

// Function to add a new product to the inventory
void addProduct(vector<Product>& inventory, int id, const string& name, double price, int quantity) {
    Product product;
    product.id = id;
    product.name = name;
    product.price = price;
    product.quantity = quantity;
    inventory.push_back(product);
    cout << "Product added successfully!" << endl;
}

// Function to display all products in the inventory
void displayInventory(const vector<Product>& inventory) {
    if (inventory.empty()) {
        cout << "Inventory is empty." << endl;
    } else {
        cout << "Inventory:" << endl;
        for (const Product& product : inventory) {
            cout << "ID: " << product.id << " | Name: " << product.name
                 << " | Price: $" << product.price << " | Quantity: " << product.quantity << endl;
        }
    }
}

int main() {
    vector<Product> inventory;

    while (true) {
        cout << "Store Management System" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display Inventory" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                int id;
                string name;
                double price;
                int quantity;

                cout << "Enter product ID: ";
                cin >> id;
                cin.ignore(); // Clear the newline character
                cout << "Enter product name: ";
                cin.ignore(); // Clear any previous newline characters
                getline(cin, name);
                cout << "Enter product price: ";
                cin >> price;
                cout << "Enter product quantity: ";
                cin >> quantity;

                addProduct(inventory, id, name, price, quantity);
                break;
            case 2:
                displayInventory(inventory);
                break;
            case 3:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
