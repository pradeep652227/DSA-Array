#include <iostream>
using namespace std;
unsigned int fact(int n,int m,int &tens,int &count)
    {
        if(n==0 || n==1)
        return 1;
        
        unsigned int ans=(fact(n-1,m,tens,count)%m);
        
        unsigned int temp=(ans*n)%m;
        if((temp%tens)==0)
            {
                count++; tens*=10;
            }
        return temp;
    }
    
int trailingZeroes(int n);
int main()
{   int n;
    cin>>n;
    cout<<trailingZeroes(n)<<endl;
    return 0;
} 
    
    
    int trailingZeroes(int N)
    {   int count{};
        int tens{10};
        int ans=fact(N,1e9,tens,count);
        cout<<tens<<endl;
        return count;
    }