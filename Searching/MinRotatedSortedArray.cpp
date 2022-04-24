#include <iostream>
#include <vector>

using namespace std;

int findMinInRotatedSorted(vector<int>& arr);

int main(){
    vector<int> arr;
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        int temp;cin>>temp;arr.push_back(temp);
    }
    
    cout<<"Minimum element in ";for(auto &i:arr)cout<<i<<" "; cout<<" is '";
    cout<<findMinInRotatedSorted(arr)<<"'"<<endl;

    return 0;
}

int findMinInRotatedSorted(vector<int>& arr){
    int n=arr.size();
    
    if(n==1)
        return arr[0];
    if(arr[0]<=arr[n-1])
        return arr[0];
    
    int l=0,r=n-1;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            
           if(arr[mid]<=arr[r])// right array is sorted in Increasing order
               r=mid;//arr[mid] could be the minimum but minimum has to be in the range [l,mid]
            else         // 3 4 5 6 1 2 OR  4 5 6 7 1 2 3 mid!<arr[r] so minimum has to be in the middle of [mid+1,r]
                l=mid+1;// minimum element has to be in the middle of [mid+1,r]
        }
    return arr[l];
    
}