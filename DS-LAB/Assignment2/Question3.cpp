#include <iostream>
#include <cstring>
using namespace std;
void swap(string arr[], int i, int j)
{
    string temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void selectionSort(string arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
       
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
      
        if (min_idx != i)
            swap(arr, min_idx, i);
    }
}
int main(){
    int n;
    cout<<"enter the number of elements: ";
    cin>>n;
    string arr[n];
    cout<<"enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionSort(arr,n);
    cout<<"sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}