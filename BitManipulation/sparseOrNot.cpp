#include <iostream>

using namespace std;

bool isSparse(int n);

int main(){
    int n; 
    cin>>n;
    
    cout<<"Number "<<n<<" is sparse or not? "<<isSparse( n)<<endl;
        
    return 0;
}

bool isSparse(int n)
{
    int msb{};
    for(int i=31;i>=0;i--)
    {
        if( (n&(1<<i))!=0 )
        {
            msb=i; break;
        }
    }
    
    int len{};
    int i;
    for( i=0;i<=msb && len<2;i++)
    {
        if((n & 1<<i)!=0)
            len++;
        else
            if(len>=2)
                return 0;
        else
            len=0;
    }
    
    if(len>=2)
        return 0;
    else
        return 1;
}