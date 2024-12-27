#include <iostream>
#include <string>
using namespace std;

// Function to sort the food items by price in increasing order
void sortMenuByPrice(string* foodItems, int* foodStock, double* foodPrices, int foodCount) {
    for (int i = 0; i < foodCount - 1; ++i) {
        for (int j = i + 1; j < foodCount; ++j) {
            if (foodPrices[i] > foodPrices[j]) {
                // Swap prices
                double tempPrice = foodPrices[i];
                foodPrices[i] = foodPrices[j];
                foodPrices[j] = tempPrice;

                // Swap food names
                string tempName = foodItems[i];
                foodItems[i] = foodItems[j];
                foodItems[j] = tempName;

                // Swap food stock
                int tempStock = foodStock[i];
                foodStock[i] = foodStock[j];
                foodStock[j] = tempStock;
            }
        }
    }
}

int main() {
    // Pointers for dynamic storage of food items
    string* foodItems = nullptr;
    int* foodStock = nullptr;
    double* foodPrices = nullptr;0
    int foodCount = 0; // Number of current food items

    // Welcome Message
    cout << "Welcome to the Cafe System!" << endl;

    // Main Loop for User Role Selection
    while (true) {
        cout << "\nAre you a (1) Cafe Owner, (2) Customer, or (3) Exit? ";
        int role;
        cin >> role;

        // Exit Option
        if (role == 3) {
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        }

        // Owner Role
        if (role == 1) {
            cout << "Enter the owner password: ";
            string password;
            cin >> password;

            // Password Validation
            if (password == "admin123") {
                // Owner Menu
                while (true) {
                    cout << "\nOwner Menu:\n";
                    cout << "1. Add new food item or update stock\n";
                    cout << "2. Delete food item\n";
                    cout << "3. Edit food item\n";
                    cout << "4. View all food items\n";
                    cout << "5. Exit\n";
                    cout << "Choose an option: ";
                    int ownerChoice;
                    cin >> ownerChoice;

                    // Add or Update Food Item
                    if (ownerChoice == 1) {
                        cout << "\nEnter the name of the food item: ";
                        string foodName;
                        cin >> foodName;

                        bool itemExists = false;

                        // Check if Food Item Exists
                        for (int i = 0; i < foodCount; ++i) {
                            if (foodItems[i] == foodName) {
                                // Update Stock and Price
                                cout << "Food item '" << foodName << "' already exists.\n";
                                cout << "Enter additional stock: ";
                                int stock;
                                cin >> stock;
                                foodStock[i] += stock;

                                cout << "Enter the new price for '" << foodName << "': ";
                                double price;
                                cin >> price;
                                foodPrices[i] = price;

                                cout << "Updated stock and price for '" << foodName << "'.\n";
                                itemExists = true;
                                break;
                            }
                        }

                        // Add New Food Item if Not Exists
                        if (!itemExists) {
                            // Increase storage dynamically
                            string* newFoodItems = new string[foodCount + 1];
                            int* newFoodStock = new int[foodCount + 1];
                            double* newFoodPrices = new double[foodCount + 1];

                            // Copy old data to new storage
                            for (int i = 0; i < foodCount; ++i) {
                                newFoodItems[i] = foodItems[i];
                                newFoodStock[i] = foodStock[i];
                                newFoodPrices[i] = foodPrices[i];
                            }

                            // Add new item
                            cout << "Enter the price of '" << foodName << "': ";
                            double price;
                            cin >> price;

                            cout << "Enter the initial stock of '" << foodName << "': ";
                            int stock;
                            cin >> stock;

                            newFoodItems[foodCount] = foodName;
                            newFoodPrices[foodCount] = price;
                            newFoodStock[foodCount] = stock;

                            // Delete old storage and update pointers
                            delete[] foodItems;
                            delete[] foodStock;
                            delete[] foodPrices;

                            foodItems = newFoodItems;
                            foodStock = newFoodStock;
                            foodPrices = newFoodPrices;
                            foodCount++;

                            cout << "Added new food item '" << foodName << "' with stock " << stock << ".\n";
                        }

                    } 
                    // Delete Food Item
                    else if (ownerChoice == 2) {
                        if (foodCount > 0) {
                            cout << "\nFood Items:\n";
                            for (int i = 0; i < foodCount; ++i) {
                                cout << i + 1 << ". " << foodItems[i] << " (Stock: " << foodStock[i] << ")\n";
                            }

                            cout << "Enter the number of the food item to delete: ";
                            int itemNum;
                            cin >> itemNum;

                            if (itemNum >= 1 && itemNum <= foodCount) {
                                cout << "Deleted food item '" << foodItems[itemNum - 1] << "'.\n";

                                // Reduce storage dynamically
                                string* newFoodItems = new string[foodCount - 1];
                                int* newFoodStock = new int[foodCount - 1];
                                double* newFoodPrices = new double[foodCount - 1];

                                // Copy old data except the deleted item
                                for (int i = 0, j = 0; i < foodCount; ++i) {
                                    if (i != itemNum - 1) {
                                        newFoodItems[j] = foodItems[i];
                                        newFoodStock[j] = foodStock[i];
                                        newFoodPrices[j] = foodPrices[i];
                                        j++;
                                    }
                                }

                                // Delete old storage and update pointers
                                delete[] foodItems;
                                delete[] foodStock;
                                delete[] foodPrices;

                                foodItems = newFoodItems;
                                foodStock = newFoodStock;
                                foodPrices = newFoodPrices;
                                foodCount--;
                            } else {
                                cout << "Invalid item number. Try again.\n";
                            }
                        } else {
                            cout << "No food items available to delete.\n";
                        }

                    } 
                    // Edit Food Item
                    else if (ownerChoice == 3) {
                        if (foodCount > 0) {
                            cout << "\nFood Items:\n";
                            for (int i = 0; i < foodCount; ++i) {
                                cout << i + 1 << ". " << foodItems[i] << " (Stock: " << foodStock[i] << ")\n";
                            }

                            cout << "Enter the number of the food item to edit: ";
                            int itemNum;
                            cin >> itemNum;

                            if (itemNum >= 1 && itemNum <= foodCount) {
                                cout << "Editing food item '" << foodItems[itemNum - 1] << "'.\n";

                                cout << "Enter the new name: ";
                                string newName;
                                cin >> newName;

                                cout << "Enter the new price: ";
                                double newPrice;
                                cin >> newPrice;

                                cout << "Enter the new stock: ";
                                int newStock;
                                cin >> newStock;

                                foodItems[itemNum - 1] = newName;
                                foodPrices[itemNum - 1] = newPrice;
                                foodStock[itemNum - 1] = newStock;

                                cout << "Updated food item '" << newName << "'.\n";
                            } else {
                                cout << "Invalid item number. Try again.\n";
                            }
                        } else {
                            cout << "No food items available to edit.\n";
                        }

                    } 
                    // View All Food Items
                    else if (ownerChoice == 4) {
                        if (foodCount > 0) {
                            sortMenuByPrice(foodItems, foodStock, foodPrices, foodCount);  // Sort food items before displaying

                            cout << "\nCurrent Food Items:\n";
                            for (int i = 0; i < foodCount; ++i) {
                                cout << i + 1 << ". " << foodItems[i] << " - $" << foodPrices[i]
                                     << " (Stock: " << foodStock[i] << ")\n";
                            }
                        } else {
                            cout << "No food items available.\n";
                        }

                    } 
                    // Exit Owner Menu
                    else if (ownerChoice == 5) {
                        cout << "Exiting Owner Menu.\n";
                        break;
                    } 
                    // Invalid Owner Menu Choice
                    else {
                        cout << "Invalid choice. Try again.\n";
                    }
                }
            } else {
                cout << "Incorrect password. Exiting the system.\n";
                break;
            }
        } 

        // Customer Role
        else if (role == 2) {
            while (true) {
                cout << "\nCustomer Menu:\n";
                cout << "1. View menu\n";
                cout << "2. Place an order\n";
                cout << "3. Exit\n";
                cout << "Choose an option: ";
                int customerChoice;
                cin >> customerChoice;

                // View Menu
                if (customerChoice == 1) {
                    if (foodCount > 0) {
                        sortMenuByPrice(foodItems, foodStock, foodPrices, foodCount);  // Sort food items before displaying

                        cout << "\nMenu:\n";
                        for (int i = 0; i < foodCount; ++i) {
                            cout << i + 1 << ". " << foodItems[i] << " - $" << foodPrices[i]
                                 << " (Stock: " << foodStock[i] << ")\n";
                        }
                    } else {
                        cout << "No food items available.\n";
                    }

                } 
                // Place an Order
                else if (customerChoice == 2) {
                    double totalPrice = 0.0;

                    while (true) {
                        cout << "\nMenu:\n";
                        for (int i = 0; i < foodCount; ++i) {
                            cout << i + 1 << ". " << foodItems[i] << " - $" << foodPrices[i]
                                 << " (Stock: " << foodStock[i] << ")\n";
                        }

                        cout << "Enter the number of the food item to order (0 to finish): ";
                        int itemNum;
                        cin >> itemNum;

                        if (itemNum == 0) break;

                        if (itemNum >= 1 && itemNum <= foodCount) {
                            cout << "Enter the quantity for '" << foodItems[itemNum - 1] << "': ";
                            int quantity;
                            cin >> quantity;

                            if (quantity > 0 && quantity <= foodStock[itemNum - 1]) {
                                foodStock[itemNum - 1] -= quantity;
                                totalPrice += foodPrices[itemNum - 1] * quantity;
                                cout << "Added " << quantity << " x " << foodItems[itemNum - 1] << " to your order.\n";
                            } else {
                                cout << "Invalid quantity or insufficient stock. Try again.\n";
                            }
                        } else {
                            cout << "Invalid food item number. Try again.\n";
                        }
                    }

                    cout << "Your total price is: $" << totalPrice << "\n";

                } 
                // Exit Customer Menu
                else if (customerChoice == 3) {
                    cout << "Thank you for visiting!\n";
                    break;
                } 
                // Invalid Customer Menu Choice
                else {
                    cout << "Invalid choice. Try again.\n";
                }
            }
        } 

        // Invalid Role
        else {
            cout << "Invalid role selected. Exiting.\n";
            break;
        }
    }

    // Free dynamically allocated memory
    delete[] foodItems;
    delete[] foodStock;
    delete[] foodPrices;

    return 0;
}
