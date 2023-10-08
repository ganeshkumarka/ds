#include<iostream>
using namespace std;

int dup_count(char arr[], int s)
{
    int freq[256]={0};
    int count=0;
    for (int i=0; i<s; i++)
    {
        freq[arr[i]]++;
    }

    for(int j=0; j<s; j++)
    {
        if(freq[arr[j]]==1)
        {
            count++;
        }
    }

    return count;

}

int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    char arr[size];
    char val;
    for(int i=0; i<size; i++)                                       //creating array
    {
        cout<<"Enter character: ";
        cin>>val;
        arr[i]=val;
    }

    for(int i=0; i<size; i++)                                       //printing array
    {
        cout<<arr[i];
        cout<<" ";
    }
    cout<<"\n";

    int count;
    count=dup_count(arr, size);
    cout<<"The duplicate count: "<<count<<"\n";

    return 0;

}

/*
Enter the size of the array: 6
Enter character: a
Enter character: b
Enter character: c
Enter character: b
Enter character: c
Enter character: d
a b c b c d
The duplicate count: 2
*/