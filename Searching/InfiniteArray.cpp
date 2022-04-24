#include <iostream>
#include <vector>

using namespace std;

int INFArray(vector<int>& arr,int target);
int binarySearch(vector<int>& arr,int target,int start,int end);

int main()
{
//    int n;
//    vector<int>arr;
//    cin>>n;
//    for(int i=0;i<n;i++)
//    {
//        int temp; cin>>temp;
//        arr.push_back(temp);
//    }
//    
//    int target{};
//    cout<<"Target element? "; cin>>target;
//    cout<<"Target appears at "<<INFArray(arr,target)<<" index "<<endl;

vector<int> arr{3, 5, 7,10,12,13};    
cout<<"Target appears at index "<<INFArray(arr,13)<<endl;
    return 0;
}

int binarySearch(vector<int>& arr,int target, int start, int end)
{
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        
        if(arr[mid]==target)
            return mid;
        else if(target<arr[mid])
                end=mid-1;
        else
                start=mid+1;
    }
    
    return -1;
}

int INFArray(vector<int>& arr,int target)
{
//    int start=0, end=1;
//    /*We'll utilise the revery binarySearch approach i.e. starting from size=2 to size=4 .... */
//   
//    while(target>arr[end])
//    {
//        int newStart=end+1;
//        end=end+(end-start+1)*2;// doubling the array
//        start=newStart;
//    }
//    
//    return binarySearch(arr,target,start,end);

int l = 0, h = 1;
	int val = arr[0];

	// Find h to do binary search
	while (val < target)
	{
		l = h;	 // store previous high
		h = 2*h;	 // double high index
		val = arr[h]; // update new val
	}

	// at this point we have updated low and
	// high indices, Thus use binary search
	// between them
	return binarySearch(arr, target,l, h);
}

