#include <iostream>
using namespace std;
void merge(double arr[], int l, int mid, int h)
{
    int n1 = mid - l + 1;
    int n2 = h - mid;
    double a[n1];
    double b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        b[j] = arr[mid + j + 1];
    }
    int i = 0, j = 0; // Initialize i and j
    int k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}

void mergeSort(double arr[], int l, int h)
{
    int mid = (l + h) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, h);

    merge(arr, l, mid, h);
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    double arr[n];
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}