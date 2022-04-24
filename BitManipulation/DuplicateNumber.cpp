#include <iostream>
#include <vector>

using namespace std;

 int findDuplicate(vector<int>& nums);
 
int main()
{
    vector<int>nums{1,3,4,2,2};
    
    cout<<" The Duplicate number is "<<findDuplicate(nums)<<endl;
    
    return 0;
}
/* Not an Optimised one, what if input is nums[5]= { 2,2,2,2,2 } Expected O/P-> 2 My O/P-> 4
int findDuplicate(vector<int>& nums)
{   int Xor{}; int sum{};
    for(int i=0;i< (int)nums.size();i++)
    {    Xor^=nums.at(i);
        sum+=nums.at(i);
    }
    
    int res1{},res2{}; // two groups containing two different kth set bit
     int sb= Xor& ~(Xor-1);// kth set bit number
    for( int i=0;i< (int)nums.size();i++)
    {
       if( (nums.at(i) & sb )!=0 )
           res1^=nums.at(i);
        else
            res2^=nums.at(i);
    }
    
    return ( ( sum - ( res1+res2 ) ) )/2;

}