#include<iostream>
using namespace std;
void insertionSort(float arr[],int n){
    float key;
    int j;
    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
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
    insertionSort(arr,n);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}