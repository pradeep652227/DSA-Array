#include <iostream>

using namespace std;
void reverseinGroups(int arr[],int n,int k);

int main()
{   int arr[]{1,2,3,4,5};
    cout<<"Before reversing in groups "; for(auto &i:arr)cout<<i<<" ";
    cout<<endl;
    reverseinGroups(arr,5,3);
    
    cout<<"After reversing "; for(auto &i:arr)cout<<i<<" ";
    cout<<endl;
    return 0;
}

void reverseinGroups(int arr[],int n,int k)
{
     for (int i = 0; i < n; i += k)
    {
        int left = i;
 
        // to handle case when k is not multiple of n
        int right = min(i + k - 1, n - 1);
 
        // reverse the sub-array [left, right]
        while (left < right)
            swap(arr[left++], arr[right--]);
 
    }
    
   /* if(k==1)
        return ;
        int left{0},right{0};
        int i{0};
        
        while(i<n)
        {
            int w_size=i+k;
            if(w_size<n)
            {
                left=i;right=i+k-1;
                while(left<right)
                 {   swap(arr[left],arr[right]);
                        left++;right--;
                 }
            }
            else{
                left=i;right=n-1;
                while(left<right)
                {
                    swap(arr[left],arr[right]);
                    left++;right--;
                }
            }
            
            i=i+k;
        }*/
}