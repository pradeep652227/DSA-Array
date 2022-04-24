#include <iostream>
#include <vector>

using namespace std;

int sansaXOR(vector<int>&nums);

int main()
{  vector<int>nums{4,5,7,5};
    cout<<"XOR sum of "; for(auto &i:nums) cout<<i<<" "; 
    cout<<"  is \t"<<sansaXOR(nums);
    return 0;
}

int sansaXOR(vector<int>&nums)
{
    int window_start{0}, window_end{0}, window_xor{0};
    int sum_xor{0};
    
//    cout<<endl;
    for(int k=2;k<(int)nums.size();k++)
    {
        for(window_start; window_start<(int)nums.size(); window_start++)
        {
            window_xor^=nums.at(window_start);
            
          //  cout<<"i= "<<window_start<<" Previous window sum-> "<<window_xor<<endl;
            if( window_start>=(k-1) )
            {
                sum_xor^=window_xor;
                window_xor^=nums.at(window_end);// removing the first element of window
                window_end++;// sliding towards the next window
            }
            
           // cout<<"i= "<<window_start<<" Reduced window sum-> "<<window_xor<<endl;
           // cout<<"sum_xor-> "<<sum_xor<<endl;
        }
       // cout<<"Total sum_xor of k= "<<k<<" is-> "<<sum_xor<<endl;
        window_xor=0;
        window_end=0;
        window_start=0;
        
       // cout<<endl;
    }
    
    return sum_xor;
}