#include <iostream>
#include <vector>
/* This program is about the only Odd Occuring number in a list/ array */

using namespace std;

int oddAppNum(vector <int> nums);
/* We'll utilise one of the properties of XOR */
/* 1. x^0= x
 * 2. x^x=0
 * 3. x^y=y^x
 * 4. x^(y^z)=(x^y)^z // XOR is associative
 */

int main()
{   vector<int> nums{4,3,4,4,4,5,5,3,3};
    
    cout<<"The only odd occuring number in "; 
    for(auto i:nums)
        cout<<i<<" ";
    cout<<"is \t"<<oddAppNum(nums)<<endl;
    
    return 0;
}

int oddAppNum(vector <int> nums)
{   int XOR{};
    for(auto i:nums)
        XOR^=i;
    
    return XOR;
}