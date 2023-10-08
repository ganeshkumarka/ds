#include<iostream>
using namespace std;

int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n>0)
    {
        return n*fact(n-1);
    }
}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;

    cout<<"The factorial of "<<n<<" is: "<<fact(n)<<"\n";

    return 0;
}
/*
Enter the number: 6
The factorial of 6 is: 720 */