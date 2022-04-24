#include <iostream>

using namespace std;

bool powerOfTwo(int n);

int main()
{
    cout<<"Enter the number:- "; int n;
    cin>>n;
    
    if( powerOfTwo(n) )
    cout<<"Number "<<n<<" is the power of 2"<<endl;
    else
    cout<<"Number "<<n<<" is not the power of 2"<<endl;
    
    return 0;
}
/* Naive Method=> Takes O( n ) Time Complexity */

//bool powerOfTwo(int n)
//{
//    if( n==0 )
//        return false;
//    
//    while( n!=1 )
//    {
//        if(n%2!=0)
//            return false;
//        n/=2;
//        
//    }
//     
//     return true;
//}

/* Brian Kerringam's algo-> Takes O(1) Time Complexity */
// As the number with power of two will have only one and only one bit which is a set bit. This bit can be anywhere from postition LSB to MSB ( excluding LSB )

bool powerOfTwo( int n )
{   
    if( n==0 )
        return false;
    if ( (n & (n-1) )== 0)// Optimised code-> return ( ( n!=0 ) && ( n& (n-1) )== 0 )
        return true;
    else
        return false;
        
}