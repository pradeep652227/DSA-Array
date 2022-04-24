#include <iostream>

using namespace std;

int countBitsFlip(int a,int b);

int main(){
    int a,b;
    cin>>a>>b;
    
    cout<<"Number of Bits to be flipped to convert "
        <<a<<" to "<<b
        <<" is \t"<<countBitsFlip(a,b)
        <<endl;
    return 0;
}

 int countBitsFlip(int a, int b){
        
        if((a^b)==0)
        return 0;
        
        int xor_val= a^b;
        
        int setBits{};
        
        while(xor_val!=0)
        {
            xor_val&=(xor_val - 1);
            setBits++;
        }
        
        return setBits;
        
    }