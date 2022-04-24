#include <iostream>
#include <cmath>

using namespace std;

int checkPattern(long n, long pattern);
long sumXor(long n);

int main()
{   cout<<sumXor(1000000000000000)<<endl;
    return 0;
}

 int checkPattern(long n,long pattern)
 {
     if((n&pattern)!=0)
        return false; //sum!=xor
    else
        return true; //sum=xor
 }


long sumXor(long n) {
    // long sum{0}, XOR{0};
    // long count{0};
    // for(long x=0;x<=n;x++)
    // {
    //     // sum=x+n;
    //     // XOR=x^n;
    //     if( (x+n)==(x^n) )
    //     count++;
    
    /* (A+B)=(A^B) +2*(A&B) so (A+B)=A^B when A&B=0 */
    
    long highest_setBit=log2(n);
    cout<<" Highest set bit-> "<<highest_setBit<<endl<<endl;
   // long pattern{0};
    long count{0}; 
    
    for(;highest_setBit>=0;highest_setBit--)
    {
        if( checkPattern(n,1<<highest_setBit)== true )// sum=xor
            count++;
    }
    
    return count;
}