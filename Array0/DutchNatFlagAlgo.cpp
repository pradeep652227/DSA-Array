//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void swap(int *a,int *b)
//{
//    int c=*a, d=*b;
//    c=c+d;
//    d=c-d;
//    c=c-d;
//    
//    *a=c , *b=d;
//}
//
//int main()
//{
//    vector <int> nums;
//    int temp; cout<<"Enter how many elements in  nums elements:- ";
//    int n; cin>>n;
//    for(int i=0;i<n;i++)
//    {
//        cin>>temp; nums.push_back(temp);
//    }
//    cout<<endl<<"Entered elements are:- ";
//    for(auto i:nums)
//    {
//        cout<<i<<" ";
//    } cout<<endl;
//    
//    int i=0, j=n-1;
//    
//    while(i<n && j>0)
//    {
//        if(nums[i]>nums[j])
//   { swap(&nums[i],&nums[j]); i++;}
//            else
//                i++;
//        if(i==j && j>0)
//            {i=0; j--;}
//           
//    }
//    
//    cout<<"Sorted numsay elements are:- ";
//    
//      for(auto i:nums)
//    {
//        cout<<i<<" ";
//    } cout<<endl;
//    
//    
//    return 0;
//}


// C++ program to sort an array
// with 0, 1 and 2 in a single pass
#include <bits/stdc++.h>
using namespace std;

// Function to sort the input array,
// the array is assumed
// to have values in {0, 1, 2}
void sort012(int a[], int arr_size)
{
	int lo = 0;
	int hi = arr_size - 1;
	int mid = 0;

	// Iterate till all the elements
	// are sorted
	while (mid <= hi) {
		switch (a[mid]) {

		// If the element is 0
		case 0:
			swap(a[lo++], a[mid++]);
			break;

		// If the element is 1 .
		case 1:
			mid++;
			break;

		// If the element is 2
		case 2:
			swap(a[mid], a[hi--]);
			break;
		}
	}
}

// Function to print array arr[]
void printArray(int arr[], int arr_size)
{
	// Iterate and print every element
	for (int i = 0; i < arr_size; i++)
		cout << arr[i] << " ";
}

// Driver Code
int main()
{
	int arr[] = {0,1,1,2,2,0,2,0 };
	int n = sizeof(arr) / sizeof(arr[0]);

	sort012(arr, n);

	cout << "array after segregation ";

	printArray(arr, n);

	return 0;
}

// This code is contributed by Shivi_Aggarwal
