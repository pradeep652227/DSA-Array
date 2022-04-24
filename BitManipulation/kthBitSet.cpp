/*kth bit set or not */

#include <iostream>

using namespace std;

bool kthbitset(int n,int k);

int main()
{   cout<<"Enter the number and then it's kth bit "; int n,k;
    cin>>n>>k;
    
    if( kthbitset(n,k))
        cout<<"bit at position "<<k<<" is set"<<endl;
    else
        cout<<"bit at position "<<k<<" is not set"<<endl;
    return 0;
}

/* Approach 1-> left shift operator */
//bool kthbitset(int n,int k)
//{
//    if(n & ( 1<<(k-1) )!=0 )
//        return 1;
//    else 
//        return 0;
//}

/* Approach 2-> right shift operator */

bool kthbitset(int n,int k)
{
    if( ( n>>(k-1) & 1 )!=0 )
        return 1;
    else 
        return 0;
}
