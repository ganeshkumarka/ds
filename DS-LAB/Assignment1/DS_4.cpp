#include<iostream>
using namespace std;

void palindrome(string& s, int first, int last)
{
    
    if(first>=last)
    {
        cout<<"The given string is a Palindrome"<<"\n";
    }
    else if(s[first]==s[last]) 
    {
        palindrome(s, first+1, last-1); 
    }
    else
    {
        cout<<"The given string is not a Palindrome"<<"\n";
    }
}

int main()
{

    cout<<"To find a stirng is palindrome or not"<<"\n";
    string s1;
 
    cout<<"Enter your string: ";
    cin>>s1;
    int size=s1.size();

    palindrome(s1, 0, size-1);

    return 0;
}

/*To find a string is palindrome or not
Enter your string: abccba
The given string is a Palindrome   */