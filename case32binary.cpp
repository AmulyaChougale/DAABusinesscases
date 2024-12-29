#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct InventoryItem {
    string name;
    int stock_level;
};

int binarySearch(vector<InventoryItem>& items, const string& target) {
    int low = 0;
    int high = items.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (items[mid].name == target) {
            return mid;
        }
        else if (items[mid].name < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
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

    string item_to_find = "Bandages";
    int index = binarySearch(inventory, item_to_find);

    if (index != -1) {
        cout << "Item found: " << inventory[index].name << " - " << inventory[index].stock_level << endl;
    } else {
        cout << "Item not found" << endl;
    }

    return 0;
}
