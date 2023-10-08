#include<iostream>
#include<cstring>
using namespace std;

string reverse(string& s, int size)
{
    
    if(size<1)
    {
        return " ";
    }
    else if(size>=1) 
    {
        return s[size-1]+reverse(s, size-1); 
    }
}

int main()
{

    cout<<"To find the reverse of a string"<<"\n";
    string s1;
 
    cout<<"Enter your string: ";
    cin>>s1;
    int size=s1.size();

    cout<<"The reverse of "<<s1<<" is: "<<reverse(s1, size)<<"\n";

    return 0;
}

/*To find the reverse of a string
Enter your string: ganesh
The reverse of ganesh is: hsenag */