#include <iostream>

using namespace std;
/* Optimised Approach:- while(n!=0) { n=n & n<<1; count++; } */
int maxConsecutiveOnes(int n);

int main(){
    int n;
    
    cout<<"Max consecutive 1's in the binary representation of "<<n<<" are "<<maxConsecutiveOnes(n)<<endl;
    return 0;
}


int maxConsecutiveOnes(int n)
    { 
        if(n==1 || n==0)
        return n;
        
        if( (n & n-1)== 0 )
        return 1;
        
        int msb{};
    for(int i=31;i>=0;i--)
    {
        if( (n&(1<<i))!=0 )
        {
            msb=i; break;
        }
    }
    
    int len{};
    
    int max_len{};
    for(int i=0;i<=msb;i++)
    {
        if((n & 1<<i)!=0)
            len++;
        else
        {
            max_len=max(max_len,len);
            len=0;
        }
    }
    
    max_len=max(max_len,len);
    return max_len;
    }