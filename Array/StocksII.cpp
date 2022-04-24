#include <iostream>
#include <vector>


using namespace std;
/*Stocks Buy and Sell- infinite transactions are allowed*/

int maxProfit(vector<int>&arr,int start,int end);
int maxProfit(vector<int>&arr);

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
    
    cout<<"Max profit in ";for(auto &i:arr) cout<<i<<" ";
//    cout<<"is:- "<<endl<<maxProfit(arr,0,n-1);
    cout<<"is:- "<<endl<<maxProfit(arr);
return 0;
}

/*Approach-1 ->Naive*/
/*int maxProfit(vector<int>&arr,int start,int end)
{
    if(start>=end)
        return 0;
    
    int curr_profit{};
    int max_profit=arr[end]-arr[start];
    
    for(int i=start;i<end;i++)
    {
        for(int j=i+1;j<=end;j++)
        {
            curr_profit=arr[j]-arr[i] + 
                        maxProfit(arr,start,i-1)+ maxProfit(arr,j+1,end);
            max_profit=max(max_profit, curr_profit);
        }
    }
    
    return max_profit;
}
*/

/*Approach-2 ->Better */

int maxProfit(vector<int>&arr)
{
    int n=arr.size();
    if(n<2)
        return -1;
  
  int profit=0;

  int min_stock{arr[0]};
  
  for(int i=0;i<n;i++)
  {
      if(i+1<n)
      {
          if(arr[i]<arr[i+1])
          {
              min_stock=arr[i]; 
              profit+=(arr[i+1]-min_stock); 
          }
      
      }
  }
  
    return profit;
}