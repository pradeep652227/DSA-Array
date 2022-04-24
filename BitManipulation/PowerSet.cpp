#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void powerset(string str);
int main()
{   cout<<"Enter the string "; string str;
    getline(cin,str);
    cout<<"Powersets of "<<str<<" are:-"<<endl;
    powerset(str);
    
    return 0;
}

void powerset(string str)
{   int n=str.length();
    int pow_size=pow(2,n);
    
    for(int counter=0;counter<pow_size;counter++)
    {
        for(int i=0;i<n;i++)
        {
            if( (counter & (1<<i) )!=0 )
                cout<<str[i];
        }
        cout<<endl;
    }
}