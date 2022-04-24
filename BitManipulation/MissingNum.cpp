#include <iostream>
#include <vector>

/* Find the missing number in a list containing n integers( n>0 ) in the range [1.. n+1]. No duplicates  */
using namespace std;

int MissinNum(vector<int> nums);

int main()
{
    vector<int> nums{ 1,4,3 };
    
    cout<<"The only Missing number in "; 
    for(auto i:nums)
        cout<<i<<" ";
    cout<<"is \t"<<MissinNum(nums)<<endl;
    
    return 0;
}

/* My Approach */

//int MissinNum(vector<int>nums)
//{
// int given_sum{}; int max{nums.at(0)};
// for(auto i:nums)
//   { given_sum+= i;
//        if(max<i)
//            max=i;
//   }  
//    
// int orig_sum{}; 
//  for(int i=1;i<=max;i++)
//      orig_sum+=i;
//    
//    return ( orig_sum - given_sum );
//}

/* Method 2-> XOR */

int MissinNum( vector<int> nums)
{
    int given_XOR{}; int max{};
    for(auto i:nums)
      {  given_XOR^=i;
        if(max<i)
            max=i;
      }
        
    int orig_XOR{};
    for(int i=1;i<=max;i++)
        orig_XOR^=i;
        
    return ( given_XOR ^ orig_XOR );
}