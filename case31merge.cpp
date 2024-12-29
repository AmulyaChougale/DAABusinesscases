#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct InventoryItem {
    string name;
    int stock_level;
};

void merge(vector<InventoryItem>& items, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<InventoryItem> B(n1), C(n2);
    for (int i = 0; i < n1; i++) B[i] = items[left + i];
    for (int i = 0; i < n2; i++) C[i] = items[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (B[i].stock_level <= C[j].stock_level) {
            items[k] = B[i];
            i++;
        } else {
            items[k] = C[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        items[k] = B[i];
        i++;
        k++;
    }
    while (j < n2) {
        items[k] = C[j];
        j++;
        k++;
    }
}

void mergeSort(vector<InventoryItem>& items, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(items, left, mid);
        mergeSort(items, mid + 1, right);
        merge(items, left, mid, right);
    }
}

int main() {
    vector<InventoryItem> inventory = {
        {"Milk", 50},
        {"Bread", 20},
        {"Cheese", 15},
        {"Butter", 30},
        {"Eggs", 25}
    };

    mergeSort(inventory, 0, inventory.size() - 1);

    for (const auto& item : inventory) {
        cout << item.name << " - " << item.stock_level << endl;
    }

    return 0;
}
