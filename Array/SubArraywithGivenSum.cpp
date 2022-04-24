#include <iostream>
#include <vector>

using namespace std;

vector<int> subarraySum(int arr[],int n, long long sum);

int main()
{
    int arr[]={1,2,3,7,5};
    
    vector<int>ans=subarraySum(arr,5,12);
    
    for(auto &i:ans)
        cout<<i<<" ";
        
    return 0;
}

    vector<int> subarraySum(int arr[], int n, long long sum)
    {
        if(sum==0)
            return {-1};
            
        int w_end{1},w_start{0};
        long long curr_sum{arr[0]};
        
        for(w_end=1;w_end<=n;w_end++)
        {
            while(curr_sum>sum && w_start<w_end-1)
            {
                curr_sum-=arr[w_start];
                w_start++;
            }
            
            if(curr_sum==sum)
            {
                return {w_start+1,w_end};
            }
            
            curr_sum+=arr[w_end];
        }
        
        if(curr_sum==sum)
        return {w_start+1,w_end};
        
        else
        return {-1};
        
//        vector<int>ans;
//        long long curr_sum{arr[0]};
//        int w_end{},w_start{};
//        
//        ans.push_back(1);
//        for(w_end=1;w_end<=n;w_end++)
//        {  
//            while(curr_sum>sum && w_start<w_end-1)
//            {
//                curr_sum-=arr[w_start];
//                ans.erase(ans.begin());
//                w_start++;
//            }
//            
//            
//            if(curr_sum==sum)
//            {
//                return ans;
//            }
//            
//            if(w_end<n)
//            {    
//                 curr_sum+=arr[w_end];
//                 ans.push_back(w_end+1);
//            }
//
//        }
//        
//        if(curr_sum==sum)
//       { ans.push_back(w_start+1);
//        
//        return ans;
//       }
//        
//        else
//            return {-1};
        
    }