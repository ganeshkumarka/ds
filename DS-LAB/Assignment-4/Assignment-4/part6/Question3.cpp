#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    int table[TABLE_SIZE];
    bool isOccupied[TABLE_SIZE];

    int hash(int key) {
        return key % TABLE_SIZE;
    }

    int quadraticProbe(int index, int i) {
        return (index + i * i) % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;  
            isOccupied[i] = false;
        }
    }

    void insert(int key) {
        int index = hash(key);
        int i = 0;
        while (isOccupied[index]) {
            index = quadraticProbe(index, i);
            i++;
        }
        table[index] = key;
        isOccupied[index] = true;
    }

    void del(int key) {
        int index = hash(key);
        int i = 0;
        while (isOccupied[index]) {
            if (table[index] == key) {
                table[index] = -1; 
                isOccupied[index] = false;
                return;
            }
            index = quadraticProbe(index, i); 
            i++;
        }
    }

    bool search(int key) {
        int index = hash(key);
        int i = 0;
        while (isOccupied[index]) {
            if (table[index] == key) {
                return true;
            }
            index = quadraticProbe(index, i); 
            i++
        }
        return false;
    }
};

int main() {
    HashTable ht;
    int choice, key;

    while (true) {
        cout << "1. Insert key" << endl;
        cout << "2. Delete key" << endl;
        cout << "3. Search key" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.del(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                cout << (ht.search(key) ? "Found" : "Not Found") << endl;
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
