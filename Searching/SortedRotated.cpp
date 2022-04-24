#include <iostream>
#include <vector>

using namespace std;

int findpivot(vector<int>& arr);
int binSearchinRotatedArray(vector<int>& arr, int target);
int binarySearch(vector<int> &arr,int l,int r,int target);

int main()
{
    vector<int>arr;
    int n;
    cin>>n;
   for(int i=0;i<n;i++)
    {
        int temp; cin>>temp;
        arr.push_back(temp);
    }
    
    int target;cout<<"Target__ ";cin>>target;
    cout<<target<<" appears at index no. "<<binSearchinRotatedArray(arr, target)<<endl;
    
    return 0;
}

int findpivot(vector<int>& arr)
{
     int n=arr.size();
        
          if(arr[0]<arr[n-1])
                    return 0;
          
        
        int l=0, r=n-1;
        while(l<r)
        {
            int mid=l+(r-l)/2;
    
            if (mid!=n-1 && arr[mid]>arr[mid+1])//4 5 6 0 1 2
                return mid+1;
            /*Maximum/Min element will lie in the array ->unsorted i.e 5 6 0 1 2 4*/
            else if(arr[mid]<arr[l])// left array is unsorted 
                r=mid-1;
            else                    // right array is unsorted
                l=mid+1;
        }
        
        if(l!=n-1)
        return l+1;
        else
            return 0;
}

int binarySearch(vector<int>& arr,int l,int r, int target)
{   
    
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        
        if(arr[mid]==target)
            return mid;
        else if(target>arr[mid])
            r=mid-1;
        else
            l=mid+1;
    }
    
    return -1;
}

int binSearchinRotatedArray(vector<int>& arr,int target)
{
    int n=arr.size();
    
    int pivotIdx=findpivot(arr);
    
    if(target==arr[pivotIdx])
        return pivotIdx;
    else if(target>=arr[0])
        return binarySearch(arr,0,pivotIdx,target);
    else
        return binarySearch(arr,pivotIdx,n-1,target);
//    
//    int firstIdx=binarySearch(arr,0,pivotIdx,target);
//    
//    if(firstIdx== -1)
//        return binarySearch(arr,pivotIdx,n-1,target);
//    else
//        return firstIdx;

//int l=0, r=n-1;
//
//if(arr[0]==target)
//    return 0;
//if(arr[n-1]==target)
//    return n-1;
//
//
//    while(l<=r)
//    {
//        int mid=l+(r-l)/2;
//        if(arr[mid]==target)
//            return mid;
//        else if(arr[l]<=arr[mid])
//        {
//            if(target<=arr[mid-1] && target>=arr[l])
//                r=mid-1;
//            else 
//                l=mid+1;
//        }
//        else
//        {
//            if(target<=arr[r] && target>=arr[mid+1])
//                l=mid+1;
//            else
//                r=mid-1;
//        }
//    }
//    
//    return -1;


}