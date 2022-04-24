#include <iostream>

using namespace std;

long long int PowMod(long long int x,long long int n,long long int M);

int main()
{   
    long long int x=2,n=10,m=1000000007;
    cout<<PowMod(x,n,m);
    
    return 0;
}

long long int PowMod(long long int x,long long int n,long long int M)
		{   
            if(n==1)
            return (x%M);
            
            long long ans;
            ans=PowMod(x,n>>1,M);
            ans=(ans*ans)%M;
            
            if(n&1)
            ans=(ans*x)%M;
            
            return ans;
		}