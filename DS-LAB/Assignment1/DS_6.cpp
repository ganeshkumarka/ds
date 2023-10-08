#include<iostream>
using namespace std;

void read(int arr[], int s)
{
    int elem;
    for(int i=0; i<s; i++)
    {
        cout<<"Enter the element: ";
        cin>>elem;
        arr[i]=elem;
    }
}

void print(int arr[], int s)
{
    for(int i=0; i<s; i++)
    {
        cout<<arr[i];
        cout<<" ";
    }
    cout<<"\n";
}

void search(int arr[], int s, int el)
{
    for(int i=0; i<s; i++)
    {
        if(arr[i]==el)
        {
            cout<<el<<" was found at index "<<i<<"\n";
        }
    } 
}

int get_max(int arr[], int s)
{
    int max=arr[0];
    for(int i=1; i<s; i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}

int get_min(int arr[], int s)
{
    int min=arr[0];
    for(int i=1; i<s; i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    return min;
}

int main()
{
    int choice;
    int size;
    int ARR[size];
    string option;
    cout<<"****ARRAY OPERATIONS****"<<"\n";

    do
    {
        cout<<"1. Create your Array"<<"\n";
        cout<<"2. Print elements of Array"<<"\n";
        cout<<"3. Search an element in the Array"<<"\n";
        cout<<"4. Print the largest and smallest value in the Array"<<"\n";
        cout<<"5. Exit"<<"\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                
                cout<<"Enter the size of the Array: ";
                cin>>size;

                read(ARR, size);
                break;

            case 2:
                print(ARR, size);
                break;

            case 3:
                int elem;
                cout<<"Enter the element to be searched: ";
                cin>>elem;
                search(ARR, size, elem);
                break;
            
            case 4:
                cout<<"The largest element in the Array is: "<<get_max(ARR, size)<<"\n";
                cout<<"The smallest element in the Array is: "<<get_min(ARR, size)<<"\n";
                break;

            case 5:
               
                break;


        }
        cout<<"Do you want to continue(y/n)? ";
        cin>>option;

    } while (option=="y");

    cout<<"You have exited successfully ."<<"\n";
    
    return 0;
}

/****ARRAY OPERATIONS****
1. Create your Array
2. Print elements of Array
3. Search an element in the Array
4. Print the largest and smallest value in the Array
5. Exit
Enter your choice: 1
Enter the size of the Array: 4
Enter the element: 1
Enter the element: 2
Enter the element: 3
Enter the element: 4
Do you want to continue(y/n)? y
1. Create your Array
2. Print elements of Array
3. Search an element in the Array
4. Print the largest and smallest value in the Array
5. Exit
Enter your choice: 2
1 2 3 4
Do you want to continue(y/n)? y
1. Create your Array
2. Print elements of Array
3. Search an element in the Array
4. Print the largest and smallest value in the Array
5. Exit
Enter your choice: 3
Enter the element to be searched: 2
2 was found at index 1
Do you want to continue(y/n)? y
1. Create your Array
2. Print elements of Array
3. Search an element in the Array
4. Print the largest and smallest value in the Array
5. Exit
Enter your choice: 4
The largest element in the Array is: 4
The smallest element in the Array is: 1
Do you want to continue(y/n)? y
1. Create your Array
2. Print elements of Array
3. Search an element in the Array
4. Print the largest and smallest value in the Array
5. Exit
Enter your choice: 5
Do you want to continue(y/n)? n
You have exited successfully*/