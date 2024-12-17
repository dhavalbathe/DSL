#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
public:
    char name[30];
    int quantity, cost, code;

    bool operator==(const Item &i1) const {
        return code == i1.code;
    }

    bool operator<(const Item &i1) const {
        return code < i1.code;
    }
};

vector<Item> list;

// Function to print an item (must be global or static)
void print(Item &i1) {
    cout << "\n";
    cout << "\nItem Name: " << i1.name;
    cout << "\nItem Quantity: " << i1.quantity;
    cout << "\nItem Cost: " << i1.cost;
    cout << "\nItem Code: " << i1.code;
}

// Function for inserting an item
void insert() {
    Item temp;
    cout << "\nEnter the item name: ";
    cin >> temp.name;
    cout << "\nEnter Item Quantity: ";
    cin >> temp.quantity;
    cout << "\nEnter Item cost: ";
    cin >> temp.cost;
    cout << "\nEnter Item code: ";
    cin >> temp.code;

    list.push_back(temp);
}

// Function to display the list of items
void display() {
    for_each(list.begin(), list.end(), print);
}

// Function to search for an item
void search() {
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item code to search: ";
    cin >> i1.code;

    p = find(list.begin(), list.end(), i1);
    if (p == list.end()) {
        cout << "\nNot found";
    } else {
        cout << "\nFound: " << endl;
        cout << "Item Name: " << p->name << endl;
        cout << "Item Quantity: " << p->quantity << endl;
        cout << "Item Cost: " << p->cost << endl;
        cout << "Item Code: " << p->code << endl;
    }
}

// Function to delete an item
void dlt() {
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to delete: ";
    cin >> i1.code;

    p = find(list.begin(), list.end(), i1);

    if (p == list.end())
        cout << "\nNot Found";
    else {
        list.erase(p);
        cout << "\nDeleted...";
    }
}

// Comparison function for sorting items by cost
bool compare(const Item &i1, const Item &i2) {
    return i1.cost < i2.cost;
}

int main() {
    int ch;
    do {
        cout << "\n***** MENU *****";
        cout << "\n1. Insert ";
        cout << "\n2. Display ";
        cout << "\n3. Search ";
        cout << "\n4. Sort ";
        cout << "\n5. Delete";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            sort(list.begin(), list.end(), compare);
            cout << "\n\nSorted on Cost";
            display();
            break;
        case 5:
            dlt();
            break;
        case 6:
            exit(0);
        }
    } while (ch != 6);
    return 0;
}
