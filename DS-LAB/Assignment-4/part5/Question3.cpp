#include <iostream>
using namespace std;

const int MAX_SIZE = 10; 

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int item) {
        if (!isFull()) {
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = item;
            size++;
        } else {
            cout << "Queue is full. Cannot enqueue." << endl;
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            int item = arr[front];
            front = (front + 1) % MAX_SIZE;
            size--;
            return item;
        } else {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }

    int getSize() {
        return size;
    }
};

int main() {
    Queue queue;
    int choice, value;

    while (true) {
        cout << "\nQueue Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Get Size" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                if (!queue.isEmpty()) {
                    cout << "Dequeued value: " << queue.dequeue() << endl;
                } else {
                    cout << "Queue is empty. Cannot dequeue." << endl;
                }
                break;
            case 3:
                if (queue.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 4:
                cout << "Queue Size: " << queue.getSize() << endl;
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
