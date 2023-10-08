#include <iostream>
using namespace std;
void swap(float arr[], int i, int j)
{
    float temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void bubbleSort(float arr[], int n)
{
    bool swaped;
    for (int i = 0; i < n; i++)
    {
        swaped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) {
                    swap(arr, j, j + 1);
                        swaped = true;
                }
        }
        if(swaped=false){
            break;
        }
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    float arr[n];
    cout<<"Enter the numbers: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubbleSort(arr,n);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    return 0;
}