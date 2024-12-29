#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct InventoryItem {
    string name;
    int stock_level;
};

int bruteForceSearch(vector<InventoryItem>& items, const string& target) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i].name == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<InventoryItem> inventory = {
        {"Antibiotics", 150},
        {"Bandages", 200},
        {"Face Masks", 180},
        {"Gloves", 250},
        {"Syringes", 300}
    };

    string item_to_find = "Antibiotics";
    int index = bruteForceSearch(inventory, item_to_find);

    if (index != -1) {
        cout << "Item found: " << inventory[index].name << " - " << inventory[index].stock_level << endl;
    } else {
        cout << "Item not found" << endl;
    }

    return 0;
}
