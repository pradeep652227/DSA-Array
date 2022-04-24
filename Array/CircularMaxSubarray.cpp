#include <iostream>
#include <vector>

using namespace std;

int circularMaxSum(vector<int>&nums);

int main()
{
    int n;
    cin>>n;
    vector<int>nums;
    
    int temp{};
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        nums.push_back(temp);
    }
    
    cout<<circularMaxSum(nums)<<endl;
    
    return 0;
}

int circularMaxSum(vector<int>&arr) 
{
    
        int n=arr.size();
        int maxSum{arr[0]},maxEnding{arr[0]};
        /*MaxSubArraySum by Kadane*/
        for(int i=1;i<n;i++)
        {
            maxEnding=max(maxEnding+arr[i],arr[i]);
            maxSum=max(maxSum,maxEnding);
        }
        
        int arrSum{0};
        for(int i=0;i<n;i++)
            arrSum+=arr[i];
        
        int minSum{arr[0]},minEnding{arr[0]};
        for(int i=1;i<n;i++)
        {
            minEnding=min(minEnding+arr[i],arr[i]);
            minSum=min(minSum,minEnding);
        }
        if(arrSum==minSum)//When all the elements are -ve then minimum sum is equal to array sum;
            return maxSum;
        int circSum=arrSum-minSum;
        
        return max(maxSum,circSum);
//    int n=nums.size();
//    int res{nums[0]};
//    
//    for(int i=0;i<n;i++)
//    {   
//        int curr_sum{nums[i]};
//        int max_sum{nums[i]};
//        int k{1};
//        
//        for(int j=i+1;k<n;j++)
//        {   k++;
//            int idx=j%n;
//            curr_sum=max(curr_sum+nums[idx], nums[idx]);
//            max_sum=max(max_sum, curr_sum);
//        }
//        
//        res=max(res,max_sum);
//    }
//    
//    return res;
}