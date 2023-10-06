#include<iostream>
#include<cmath>
using namespace std;

void binary(int n)
{
    if(n==1)
    {
        cout<<1;
    }
    else if(n>1)
    {
        binary(n/2);
        cout<<n%2;  
    }
}



int main()
{
    int num;
    cout<<"Convert decimal form to binary form"<<"\n";
    cout<<"Enter the number: ";
    cin>>num;


    cout<<"The binary form of "<<num<<" is ";
    binary(num);
    cout<<"\n";
    
    return 0;
}

/*Convert decimal form to binary form
Enter the number: 10
The binary form of 10 is 1010 */