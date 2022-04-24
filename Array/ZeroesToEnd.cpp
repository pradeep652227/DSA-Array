#include <iostream>
#include <vector>

using namespace std;
/*Move all zeroes to the end of an array*/

void moveZeroes(vector<int>&arr);

int main()
{   
    int n;
    cin>>n;
    vector<int>arr;
    
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp; arr.push_back(temp);
    }
    

    cout<<"Previously:- "; for(auto &i:arr) cout<<i<<" ";
    cout<<endl;
    
    moveZeroes(arr);
    cout<<"Modified Array:- ";for(auto &i:arr) cout<<i<<" ";
    
    cout<<endl;
    
    return 0;
}

/*Efficient Approach*/

void moveZeroes(vector<int>&arr)
{
    int count0s{0};
    int n=arr.size();
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[count0s],arr[i]);
            count0s++;
        }
    }
}

/* Two Pointer Approach */
/*void moveZeroes(vector<int>&arr)
{
    int start{0},end{arr.size()-1};
    
    while(start<end)
    {
        if(arr[end]!=0)//it should be at start
        {
            if(arr[start]==0)
            {
                swap(arr[start],arr[end]);
                start++;end--;
            }
            else
                start++;
        }
        
        else if(arr[end]==0)
        {
            if(arr[start]==0)
                end--;
            else
                start++;
        }
            
    }
    
    return ;
}*/