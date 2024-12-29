#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct InventoryItem {
    string name;
    string expiration_date; // For simplicity, using string to represent date
};

int partition(vector<InventoryItem>& items, int l, int r) {
    InventoryItem p = items[l];
    int i = l, j = r + 1;

    while (true) {
        do {
            i++;
        } while (i <= r && items[i].expiration_date < p.expiration_date);

        do {
            j--;
        } while (items[j].expiration_date > p.expiration_date);

        if (i >= j)
            break;

        swap(items[i], items[j]);
    }

    swap(items[l], items[j]);
    return j;
}

void quickSort(vector<InventoryItem>& items, int l, int r) {
    if (l < r) {
        int s = partition(items, l, r);
        quickSort(items, l, s - 1);
        quickSort(items, s + 1, r);
    }
}

int main() {
    vector<InventoryItem> inventory = {
        {"Milk", "01/12/2024"},
        {"Bread", "25/12/2024"},
        {"Cheese", "15/12/2024"},
        {"Butter", "10/12/2024"},
        {"Eggs", "30/12/2024"}
    };

    quickSort(inventory, 0, inventory.size() - 1);

    for (const auto& item : inventory) {
        cout << item.name << " - " << item.expiration_date << endl;
    }

    return 0;
}
