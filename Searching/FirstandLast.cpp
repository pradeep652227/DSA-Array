#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target);

int main()
{   vector<int>nums{1,2,3,3,3,4};
    
    vector<int>temp=searchRange(nums,3);
    for(auto &i:temp)
        cout<<i<<" ";
        cout<<endl;
    
    return 0;
}


 int search(vector<int>& nums, int n,int target,bool flag)
    {   
         int l{0},r{n-1};
        int beg_occurr{-1};
        int last_occurr{beg_occurr};
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {   
                if(flag)//last occurr
                {
                     if(mid==n-1 || nums[mid+1]!=target)
                         {last_occurr=mid; break;}  
                    else
                            l=mid+1;
                }
                else
                {//first occurr
                         if(mid==0 || nums[mid-1]!=target)
                             { beg_occurr=mid; break;} 
                        else
                            r=mid-1;
                } 
            }
            else if(target<nums[mid])
                    r=mid-1;
            else
                l=mid+1;
        }
        
        if(flag)
            return last_occurr;
        else
            return beg_occurr;
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       int n=nums.size();
        if(n==0)
            return {-1,-1};
        
        int beg_occurr{-1};
        beg_occurr=search(nums,n,target,0);
       
        if(beg_occurr==-1)
            return {-1,-1};
        
        int last_occurr{beg_occurr};
        last_occurr=search(nums,n,target,1);
        
        return {beg_occurr,last_occurr};
        
    }

 /*vector<int> searchRange(vector<int>& nums, int target) {
       int n=nums.size();
        if(n==0)
            return {-1,-1};
        
        int beg_occurr{-1};
        int l{},r{n-1};
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                if(mid==0 || nums[mid-1]!=target)
                { beg_occurr=mid; break;} 
                else
                    r=mid-1;
            }
            else if(target<nums[mid])
                    r=mid-1;
            else
                l=mid+1;
        }
        
        if(beg_occurr==-1)
            return {-1,-1};
        
        int last_occurr{beg_occurr};
        l=beg_occurr;r=n-1;
        
           while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                if(mid==n-1 || nums[mid+1]!=target)
                {last_occurr=mid; break;}  
                else
                    l=mid+1;
            }
            else if(target<nums[mid])
                    r=mid-1;
            else
                l=mid+1;
        }
        
        return {beg_occurr,last_occurr};
        
    }
*/