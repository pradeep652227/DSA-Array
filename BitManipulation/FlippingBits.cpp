#include <iostream>

using namespace std;

/* Simple approach is:- unsigned int answer{n}; return ~answer; i.e narrowing conversion from long int to int then doing the negation and returing an unsigned int */
unsigned long flippingBits(long n);

int main()
{   long n; cin>>n;
    cout<<"Flipped "<<n<<" is\t"<<flippingBits(n)<<endl;
    
    return 0;
}

unsigned long flippingBits(long n)
{   
    unsigned long answer{n};
    //unsigned int answer{0};
    for(int i=0;i<32;i++)
    {   // answer|= ( n^(1<<i) );// ith bit flipped per iteration while remaining bits were kept unflipped( in each iteration)
        answer= (answer ^ (1<<i) );
    }
    
    return answer;
    
}