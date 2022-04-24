#include <iostream>

using namespace std;

int rightMostDiffBit(int m,int n);

int main(){
    int m,n;
    cin>>m>>n;
    
    cout<<"Rightmost Different bit in "
        <<m<<" and "<<n
        <<" is \t"<<rightMostDiffBit(m,n)
        <<endl;
    return 0;
}

int rightMostDiffBit(int m,int n)
{
    if( (m^n)==0 )
        return -1;
    int Max{}; Max=( (m>n)?m:n );
    int msb{};
    
    for(int i=31;i>=0;i--)
    {
        if( (Max&(1<<i))!=0 )
        {
            msb=i; break;
        }
    }
    
    for(int i=0;i<=msb;i++)
    {
        int res1=m&(1<<i);
        int res2=n&(1<<i);
        
        if(res1!=res2)
         return i+1;
    }
    
    return -1;
    
}