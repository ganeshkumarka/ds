#include<iostream>
using namespace std;

int main()
{
    int size;
    cout<<"Enter the size of your array: ";
    cin>>size;

    int arr[size];
    int value;
    for(int i=0; i<size; i++)
    {
        cout<<"Enter the element: ";
        cin>>value;
        arr[i]=value;
    }

    int max=arr[0];
    for(int i=0; i<size; i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    cout<<"The largest element is: "<<max<<"\n";

    
    int i, key, j;
    for(i=1; i<size; i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    
    cout<<"The sorted array: ";
    for(int m=0; m<size; m++)
    {
        cout<<arr[m];
        cout<<" ";
    } 
    cout<<"\n";
    
    int k;
    cout<<"To find the kth element, enter k: ";
    cin>>k;

 
    cout<<"The "<<k<<" largest element is "<<arr[(size-1)-(k-1)]<<"\n";
    
    return 0;
}

/* 
Enter the size of your array: 5
Enter element: 11
Enter element: 23
Enter element: 36
Enter element: 8
Enter element: 24
The largest element is: 36
The sorted array: 8 11 23 24 36
To find the kth element, input k: 2
The 2 largest element is 24
*/