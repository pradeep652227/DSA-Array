#include <iostream>
#include <vector>

using namespace std;

void twoOddAppear(vector<int> nums);

int main()
{   vector<int> nums;
    cout<<"Enter number of array elements "; int n; cin>>n;
    cout<<"Enter the array elements "; 
    int temp{};
    for(int i{};i<n;i++)
    {
        cin>>temp;
        nums.push_back(temp);
    }
    
    twoOddAppear(nums);
    return 0;
}

void twoOddAppear(vector<int>nums)
{
    int XOR{};
    for(auto i:nums)
        XOR^=i;
    /* Now this XOR is the resultant of those two odd appearing no.s as all the even occuring numbers cancelled out each other when we did the xor operation*/
    int sb=XOR & ~(XOR-1);// getting a number with only one bit which is the right most set bit of XOR.
    
    int res1{},res2{};//res1 will have numbers including the same rightmost set bit like it is in sb otherwise they'll fall in res2
    for(auto i:nums)
    {
        if( (sb & i)!=0 )
            res1^=i;
        else
            res2^=i;
    }// What we did is that we selected a kth set bit number,let's say, rightmost set bit no. then modularised the numbers in two groups based on this criteria that one group
    // will contain numbers having the same kth set bit and the other one will not have such kth set bit.
    
    cout<<"Two Odd apearing numbers in the list "; for(auto i:nums) cout<<i<<" ";
    cout<<"\tare:- "<<res1<<" "<<res2<<endl;
    
}