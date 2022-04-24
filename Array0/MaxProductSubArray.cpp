#include <iostream>
#include <vector>

using namespace std;

int Max_product(vector <int> arr,int n);
int main()
{
     vector<int> arr;
    int n; cout<<"Enter no. of array elements "; cin>>n;
    cout<<"Enter array elements "; int temp;
    for(int i=0;i<n;i++) { cin>>temp; arr.push_back(temp); }
    
    cout<<"Max product is "<<Max_product(arr,n)<<endl;
    
    return 0;
}

int Max_product(vector <int> arr,int n)
{
    	    int k=2; long int prod=1;
    int window_start=0;
    long int max_prod;
    if(n<=1)
        return arr[0];
    else 
  {  max_prod=(arr[0]*arr[1]);
  
    for(int i=0;i<n;i++)
    {
        prod*=arr[i];
        if(i> (k-1) )
        {
            if(max_prod < prod)
                max_prod=prod;
            int temp=k;
            for(int j=i+1;j<n;j++)
            {
                prod*=arr[j];
                if(j> (temp-1) ){
                    if(max_prod < prod)
                      max_prod=prod;
                      temp++;
                }
            }
            if(arr[window_start]!=0) prod/=arr[window_start];
            
            window_start++;
        }
    }
    
    return max_prod;
  }
  
}