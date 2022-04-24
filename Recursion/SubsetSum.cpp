#include <iostream>

using namespace std;
/* Two approaches:- 1.) Use either to include the element or exclude the element in every recursive call and at the end when size becomes zero, check the sum 
 *                  2.) Use given sum and instead of checking sum at the end, check whether the current elem is 0(when n=0) as we are either sub. the sum from the array elem in one kind of recursive call 
 *                   and keeping the sum variable in another set of recursive calls.
 * */

//int CountSets(int arr[], int n, int sum, int elem);
int CountSets(int arr[], int n, int sum);

int main()
{
// int n; cin>>n;
//   int arr[n];

int arr[5]{10,5,2,3,6 };
  // cout<<" Number of subsets having sum equals to 8 are "<<CountSets(arr,5,8,0)<<endl;
   
   cout<<" Number of subsets having sum equals to 8 are "<<CountSets(arr,5,8)<<endl;
    return 0;
}

/*int CountSets(int arr[], int n, int sum, int elem)
{
    if(n==0)
        return (sum==elem)? 1:0;
    
    return CountSets(arr,n-1,sum,elem) // excluding arr[n-1]
           + CountSets(arr,n-1,sum, elem+arr[n-1]);// including arr[n-1]
    
} */

int CountSets(int arr[], int n, int sum)
{
    if(n==0)
        return (sum==0)? 1:0;
    
    return CountSets(arr,n-1,sum) // excluding arr[n-1]
           + CountSets(arr,n-1,sum-arr[n-1]);// including arr[n-1]
    
}