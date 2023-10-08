#include<iostream>
#include<algorithm>
using namespace std;

void join_array(int arr1[], int arr2[],int arr3[], int size)
{
    sort(arr1, arr1+size);
    sort(arr2, arr2+size);

    cout<<"Sorted Array 1: ";
    for(int i=0; i<size; i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<"\n";

    cout<<"Sorted Array 2: ";
    for(int j=0; j<size; j++)
    {
        cout<<arr2[j]<<" ";
    }
    cout<<"\n";

    int n_size=0;
    for(int x=0; x<size; x++)
    {
        arr3[n_size]=arr1[x];
        n_size++;
    }
    
    for(int y=0; y<size; y++)
    {
        arr3[n_size]=arr2[y];
        n_size++;
    }

    sort(arr3, arr3+n_size);
    reverse(arr3, arr3+n_size);

    cout<<"The Merged Reverse Sorted Array: ";
    for(int z=0; z<(size*2); z++)
    {
        cout<<arr3[z]<<" ";
    }
    cout<<"\n";

}

int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int arr1[size];
    int arr2[size];
    int val;
    
    cout<<"Array 1:"<<"\n";
    for(int i=0; i<size; i++)
    {
        cout<<"Enter element: ";
        cin>>val;
        arr1[i]=val;
    }

    cout<<"Array 2:"<<"\n";
    for(int j=0; j<size; j++)
    {
        cout<<"Enter element: ";
        cin>>val;
        arr2[j]=val;
    }
    
    int arr3[size*2];
   
    join_array(arr1, arr2, arr3, size);

}

/*
Enter the size of the array: 3
Array 1:
Enter element: 2
Enter element: 5
Enter element: 3
Array 2:
Enter element: 6
Enter element: 8
Enter element: 4
Sorted Array 1: 2 3 5
Sorted Array 2: 4 6 8 
The Merged Reverse Sorted Array: 8 6 5 4 3 2*/