#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    int table[TABLE_SIZE];
    bool isOccupied[TABLE_SIZE];

    int hash1(int key) {
        return key % TABLE_SIZE;
    }

    int hash2(int key) {
        
        return 7 - (key % 7);
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1; 
            isOccupied[i] = false;
        }
    }

    void insert(int key) {
        int index = hash1(key);
        int step = hash2(key);
        while (isOccupied[index]) {
            index = (index + step) % TABLE_SIZE; 
        }
        table[index] = key;
        isOccupied[index] = true;
    }

    void del(int key) {
        int index = hash1(key);
        int step = hash2(key);
        while (isOccupied[index]) {
            if (table[index] == key) {
                table[index] = -1; 
                isOccupied[index] = false;
                return;
            }
            index = (index + step) % TABLE_SIZE;
        }
    }

    bool search(int key) {
        int index = hash1(key);
        int step = hash2(key);
        while (isOccupied[index]) {
            if (table[index] == key) {
                return true;
            }
            index = (index + step) % TABLE_SIZE; 
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
                if(ht.search(key)){
                    cout<<"Found";
                }else{
                    cout<<"Not Found";
                }
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
