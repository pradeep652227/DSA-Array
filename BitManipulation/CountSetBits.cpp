/* Count Set Bits */

#include <iostream>

using namespace std;

int countSetBit( int n );

int main()
{   cout<<"Enter the number"; int n;
    cin>>n;
    
    cout<<"Number of set bits in "<<n<<" are:- "<<countSetBit(n)<<endl;
    return 0;
}
/* Approach 1-> Naive */

//int countSetBit(int n)
//{   int count{};
//
//    while( n!=0 )
//    {
//        count+= n%2;
//        n/=2;
//    }
//    
//    return count;
//}

/* Approach 2-> Brian Kerringam's Algorithm */

//int countSetBit( int n )
//{
//    int count{};
//    while(n>0)
//    {    n=n& ( n-1 );
//        count++;
//    }
//    return count;
//}

/* Approach 3-> Lookup table method */
// We'll do some precomputation in terms of storing set bits from 0 to 255

int countSetBit( int n )
{
    int table[256]{};
    table[0]=0;
    
    for(int i=1;i<=255;i++)
        table[i]= (i&1) + table[i/2]; // no. of set bits in n is equivalent to no. of set bits in n ( if n is even )
                                    // or it's 1 + no. of set bits in n ( if n is odd )
                                    
    /* Below is the implementation of the logic:- Dividing our number into chunks of 8 bits then checking number of set bits in those modularised chunks */
    
    int count= table[ n & 255 ];// ff is the hex code for 11111111 
    n=n>>8; // right shifting the computed 08 bits 
    
    count+=table[n & 255 ];
    n=n>>8;
    
    count+=table[n & 255 ];
    n>>=8;
    
     count+=table[n & 255 ]; 
    n>>=8;
    
    return count;
}