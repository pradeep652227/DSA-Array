#include <iostream>

using namespace std;

int main()
{
    int num1,num2; cin>>num1>>num2;
    
    int max{}; 
    (num1>num2)?max=num1:(max=num2);
    
    int msb{};
    for(int i=31;i>=0;i--)
    {
        if(max&(1<<i))
       {     msb=i;
            break;
       }
    
    }
    cout<<"MSB "<<msb<<endl;
    
    int count{};
    for(int i=0;i<=msb;i++)
    {
        int bit_num1=num1 & 1<<i; cout<<bit_num1<<" ";
       int  bit_num2=num2 & 1<<i; cout<<bit_num2<<endl;
        
        if(bit_num2 != bit_num1)
            count++;
    }
    
    cout<<count<<endl;

    return 0;
}