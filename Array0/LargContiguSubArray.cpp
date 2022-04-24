#include <iostream>

using namespace std; 

int Max(int a,int b);
int Kadane_algo(int arr[], int size);

int main()
{
    int arr[5]={1,2,3,-2,5};
    
    cout<<"Array elements:- ";
    for(auto i:arr)
    cout<<i<<" ";
    cout<<endl;
    
    int max_sum=Kadane_algo(arr,5);
    cout<<"     Max sub-array sum of the above array is:- "<<max_sum<<endl;
    
    return 0;
}

int Max(int a,int b)
{
    //Suppose a>b
    if(a<b)
        return b;
        else return a;
}

int Kadane_algo(int arr[],int n)
{
//    int window_sum{0}, max_sum{arr[0]}, window_start{0};
//    
//    for(int i=0,k=1 ; k<=n ;)
//    {
//        window_sum+=arr[i];
//        
//        if(i>=(k-1) )
//        {
////            max_sum=Max(window_sum,max_sum);
//if(max_sum<window_sum){
//                max_sum=window_sum;
//            }
//            window_sum-=arr[window_start];
//            window_start++; // sliding the window ahead
//        }
//        
//        if(i==n-1)
//        {
//            k++; i=0; window_start=0; window_sum=0;
//        }else{
//            i++;
//        }
//    }
//    
//    return (max_sum);

long long int window_sum{0}; long long int max_sum{arr[0]}; 
        int window_start{0};  int k=1;
        
        for(int window_end{0};k<=n;)
        {
            window_sum+=arr[window_end];
            if(window_end>=(k-1))
            {
                if(max_sum<window_sum)
                max_sum=window_sum;
                window_sum-=arr[window_start];
                window_start++;
            }
            window_end++;
            if(window_end==n)
            {
                window_sum=0; window_start=0;k++; window_end=0;
            }
        }// return vector <int>{
        
        return max_sum;
}