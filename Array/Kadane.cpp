#include <iostream>
#include <vector>

using namespace std;

int maxSumSubArray(vector<int>& arr);

int main()
{   vector<int> arr{-2,1,-3,4,-1,2,1,-5,4};
    cout<<"Max subArray sum is "<<maxSumSubArray(arr)<<endl;
    return 0;
}

int maxSumSubArray(vector<int>& arr)
{
    int n=arr.size();
          if(n==0)
              return -1;
          if(n==1)
              return arr[0];

         int maxSum{arr[0]},maxEnding{arr[0]};
         for(int i=1;i<n;i++)
         {
             maxEnding=max(arr[i],maxEnding+arr[i]);
             maxSum=max(maxSum,maxEnding);
         }

            return maxSum;

        }
}