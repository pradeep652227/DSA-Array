#include <iostream>

using namespace std;
unsigned int reverseBits(unsigned int n);

int main()
{   
    int n;
    cin>>n;
    
    cout<<reverseBits(n)<<endl;
    return 0;
}

  unsigned int reverseBits(unsigned int n)
    {
        unsigned int ans{};
        int msb{};
        for(int i=31;i>=0;i--)
        {
            if((n&1<<i)!=0)
            {
                msb=i;break;
            }
        }
        
        unsigned int bit1{},bit2{};
        
        int i=0, j=msb;
        while(i<=j)
        {
            bit1=1<<j;
            bit2=1<<i;
            
            bit1=(n&bit1); 
            bit1=bit1>>(j-i);
            
            bit2=(n&bit2);
            bit2=bit2<<(j-i);
            
            ans=ans | (bit1 | bit2);
            
            i++;j--;
            
        }
        
        return ans;
        
    }