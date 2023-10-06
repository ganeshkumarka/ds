#include<iostream>
using namespace std;
class Stack{
    public:

    int *arr;
    int top=-1;
    int size;
    Stack(int size){
        size=size;
        arr = new int[size];
        for(int i=0;i<size;i++){
            arr[i]=0;
        }
    }
    void push(int value){
        if(isFull()){
            cout<<"Stack overflow ";
        }
        else{
            arr[top+1]=value;
            top++;
        }
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow.";
        }
        else{
            cout<<"poped value: "<<arr[top];
            arr[top]=0;
            top--;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(){
        if(top==size){
            return true;
        }
        else{
            return false;
        }
    }
    void Size(){
        if(isEmpty()){
            cout<<"number of elements is 0.";
        }else{
            cout<<"number of elements is "<<top;
        }
    }
    void display(){
        for(int i=0;i<size;i++){
        cout<<"/nThe elements are: "<<arr[i];}
    }

};
int main(){
    int size;
    cout<<"Enter the size of the Stack: ";
    cin>>size;
    Stack s1(size);
    int choice, value;

    while (true) {
        cout << "\nStack Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Get Size" << endl;
        cout << "6. Display Elements" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to push: ";
                cin >> value;
                s1.push(value);
                break;
            case 2:
                s1.pop();
                break;
            case 3:
                if (s1.isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 4:
                if (s1.isFull()) {
                    cout << "Stack is full." << endl;
                } else {
                    cout << "Stack is not full." << endl;
                }
                break;
            case 5:
                s1.Size();
                break;
            case 6:
                s1.display();
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}