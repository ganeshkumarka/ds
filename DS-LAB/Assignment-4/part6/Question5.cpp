#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;

    node(int n)
    {
        data = n;
        next = nullptr;
    }
};

class hash_table
{
    const static int tb_size = 10;
    node *table[tb_size];

public:
    hash_table()
    {
        for (int i = 0; i < tb_size; i++)
        {
            table[i] = nullptr;
        }
    }

    int hash(int key)
    {
        return key % tb_size;
    }

    void INSERT(int key)
    {
        int pos = hash(key);
        node *new_node = new node(key);

        if (table[pos] == nullptr)
        {
            table[pos] = new_node;
        }
        else
        {
            node *temp = table[pos];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    void DELETE(int key)
    {
        int pos = hash(key);
        node *prev = nullptr;

        node *temp = table[pos];
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                if (prev == nullptr)
                {
                    table[pos] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "\nKey not found";
    }

    void SEARCH(int key)
    {
        int pos = hash(key);
        node *temp = table[pos];

        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                cout << "\nFound key";
                return;
            }
            temp = temp->next;
        }
        cout << "\nKey not found";
    }

    void SHOW()
    {
        for (int i = 0; i < tb_size; i++)
        {
            cout << "Index " << i << ": ";
            node *temp = table[i];
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
    }
};

int main()
{
    hash_table ht;
    int choice, key;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display Table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.INSERT(key);
            break;

        case 2:
            cout << "Enter key to delete: ";
            cin >> key;
            ht.DELETE(key);
            break;

        case 3:
            cout << "Enter key to search: ";
            cin >> key;
            ht.SEARCH(key);
            break;

        case 4:
            ht.SHOW();
            break;

        case 5:
            exit(0);

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}