#include <iostream>

using namespace std;

int main()
{   int n; cin>>n;
    cout<<"Enter i'th and j'th bits of n "; 
    int i,j; cin>>i>>j;
    
   /* Wrong one-> int temp1{}, temp2{};
    
    temp1= n&(1<<i); temp2= n&(1<<j);
    
    if(temp1==0)
        n|=temp2>>(j-i);
    else
        n|=n&temp2>>(j-i);
    
    if(temp2==0)
        n|=temp1<<(j-i);
        
    else
        n|=n&temp1<<(j-i);
    
    cout<<"Number after swapping of bits is "<<n<<endl;
     */
     
     
    return 0;
}