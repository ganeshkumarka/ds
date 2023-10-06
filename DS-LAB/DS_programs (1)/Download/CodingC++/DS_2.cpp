#include<iostream>
#include<cmath>
using namespace std;

int sum(int n)
{
    if(n==0)
    {
       return 0; 
    }
    else if(n>0)
    {
        return n%10+sum(floor(n/10));
    }
    
}

int main()
{
    int num;
    cout<<"To Find the sum of digits of a number"<<"\n";
    cout<<"Enter the number: ";
    cin>>num;

    cout<<"The sum of digits of "<<num<<" is: "<<sum(num)<<"\n";

    return 0;
}

/*To Find the sum of digits of a number
Enter the number: 1234
The sum of digits of 1234 is: 10 */